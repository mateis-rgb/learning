// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Copyright (c) 2008 Stephan Busker
// + Nur für den privaten Gebrauch
// + FOR NON COMMERCIAL USE ONLY
// + www.Mikro-control.de
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Es gilt für das gesamte Projekt (Hardware, Software, Binärfiles, Sourcecode und Dokumentation), 
// + dass eine Nutzung (auch auszugsweise) nur für den privaten (nicht-kommerziellen) Gebrauch zulässig ist. 
// + Sollten direkte oder indirekte kommerzielle Absichten verfolgt werden, ist mit uns (stephan.busker@mikro-control.de) Kontakt 
// + bzgl. der Nutzungsbedingungen aufzunehmen. 
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Keine Gewähr auf Fehlerfreiheit, Vollständigkeit oder Funktion
// + Benutzung auf eigene Gefahr
// + Wir übernehmen keinerlei Haftung für direkte oder indirekte Personen- oder Sachschäden
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Redistributions of source code (with or without modifications) must retain the above copyright notice, 
// + this list of conditions and the following disclaimer.
// +   * Neither the name of the copyright holders nor the names of contributors may be used to endorse or promote products derived
// +     from this software without specific prior written permission.
// +   * The use of this project (hardware, software, binary files, sources and documentation) is only permitted 
// +     for non-commercial use (directly or indirectly)
// +     Commercial use is only permitted with our written permission
//
// +  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// +  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// +  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// +  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// +  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// +  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// +  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// +  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// +  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// +  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// +  POSSIBILITY OF SUCH DAMAGE. 
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <stdio.h>
#include <avr/io.h>
#include "fat16.h"
#include "sdc.h"

//________________________________________________________________________________________________________________________________________
// Module name:			fat16.c 
// Compiler used:		avr-gcc 3.4.5
// Last Modifikation:	2.10.2008
// Version:				1.29
// Authors:				Stephan Busker 	
// Description:			Source files for FAT16 implementation with read and write-access using AVR-Mikrocontrollers
//						Copyright (C) 2007 Stephan Busker
//........................................................................................................................................
// Functions:			u8 			InitFat16(void);		
//						u8 			fopen_(s8 *fname,s8 mode);
//						void 		fclose_(File *file);
//						u32 		fread_(void *buffer, u32 size, u32 count, File *file); 
//						u32 		fwrite_(void *buffer, u32 size, u32 count, File *file);
//						s16  		fseek_(File *file, s32 offset, s16 origin);
//	         			s8 			fgets_(s8 *string, s16 count, File *file);
//						u8 			fputchar_(File *file,s8 c);
//						s16 		fgetchar_(File *file);
//						u8 			fputs_(File *file,s8 *string);
//						s8 *		fgets(s8 *, s16, File);
//						u8 			fexist_(u8*);
//						u8 			mkdir_(s8 *name);
//						u8 			chdir_(s8 *name);
//						u8 			rmdir_(s8 *dname)
//						u8 			findfirst_(s8 *fname, Find *item, u8 attribute);
//						u8 			findnext_(Find *item);
//						u8 			fdelete_(s8 *fname)
//						u16			feof_(File);
//........................................................................................................................................
// ext. functions:		extern u8 SDC_GetSector  (u32,u8 *);		
//						extern u8 SDC_PutSector (u32,u8 *);
//........................................................................................................................................
//
// URL:					www.Mikro-Control.de
// mailto:				stephan.busker@mikro-control.de
//________________________________________________________________________________________________________________________________________



//________________________________________________________________________________________________________________________________________
// 
// Global variables needed for read- or write-acces to the FAT16- filesystem.
//				
//________________________________________________________________________________________________________________________________________

u8 		SectorsPerCluster 		= 0;											// how many sectors does a cluster contain?
u8		FatCopies 				= 0;											// Numbers of copies of the FAT
u16		PossibleRootEntries 	= 0;											// Possible number of entries in the root directory.
u16		SectorsPerFat 			= 0;											// how many sectors does a fat16 contain?
u32		ReservedSectors 		= 0;											// Sectors reserved by the filesystem.
u32		FirstPartitionSector 	= 0;											// Distance in sectors between the first partition and the master bootrecord.
u32		FileAllocationTable 	= 0;											// pointer to the first FAT
u32		RootDirectory 			= 0;											// Pointer to the rootdirectory of the first partition.
u32		FirstDataCluster 		= 0;											// Pointer to the first cluster containing data (cluster0).
u32		CWD						= 0;											// Pointer startcluster to the current working directory


struct DirEntry 	*DirectoryEntry;											// Pointer to an entry of the directory.
struct FatEntry 	*Fat;														// Pointer to an entry of the fat (next clusterposition).

File FilePointer[__MAX_FILES_USED];												// Allocate Memmoryspace for each filepointer used.


//________________________________________________________________________________________________________________________________________
// Funtion: 	InitFat16(void);
// 
// Description:	This function reads the Masterbootrecord and finds the position of the Volumebootrecord, the FAT and the Rootdirectory
//				and stores the information in global variables.
//
// Returnvalue: The function returns "0" if the filesystem could not be initialized because no partition was found on the volume. 
//________________________________________________________________________________________________________________________________________

u8 InitFat16(void)
{	
	u8 retvalue = 0;
    u8	cnt	= 0;
	struct VBR_Entry *VBR;														// Pointer to the VolumeBootRecord.
	struct MBR_Entry *MBR;														// Pointer to the masterbootrecord.	
	File *file;

	for(cnt=0;cnt<__MAX_FILES_USED;cnt++)
	{
		FilePointer[cnt].state = _UNUSED;										// declare the filepointers as unused.
	}
	
	file = &FilePointer[0];

	SD_Result_t res;
	while(((res = SDC_Init()) != SD_SUCCESS) && (cnt++<100));

	if(cnt <100)																// sdcard initialised succesfully
	{
		SDC_GetSector((u32)_MBR_SECTOR,file->buffer);							// Read the MasterBootRecord from mmc.
		MBR = (struct MBR_Entry *) file->buffer;
		FirstPartitionSector = MBR->PartitionEntry1.NoSectorsBeforePartition;
		if((MBR->PartitionEntry1.Type == _FAT16_32_MB_BIOS_Extension) || 
		   (MBR->PartitionEntry1.Type == _FAT16_ST_32_MB) ||
		   (MBR->PartitionEntry1.Type == _FAT16_LT_32_MB))
		{
			SDC_GetSector(FirstPartitionSector,file->buffer);					// Read the volume bootrecord from mmc.	
	
			VBR = (struct VBR_Entry *) file->buffer;							// Enter the VBR using the structure VBR_Entry.
			SectorsPerCluster	= VBR->SectorsPerCluster;						// Number of sectors per cluster. Depends on the memorysize of the sd-card.
			FatCopies 			= VBR->NoFATCopies;								// Number of fatcopies.
			PossibleRootEntries = VBR->MaxRootEntries;							// How many Entries are possible in the rootdirectory (FAT16 allows max. 512 entries).
			SectorsPerFat 		= VBR->SectorsPerFAT;							// The number of sectors per FAT.
			ReservedSectors		= VBR->ReservedSectors;							// calculate the sectorpositon of the FAT, the Rootdirectory and the first Datacluster.

			FileAllocationTable	=   (u32)(FirstPartitionSector + (u32)ReservedSectors);							// Calculate the position of the FileAllocationTable.
			RootDirectory		=   (u32)((u32)FileAllocationTable + (u32)((u32)SectorsPerFat*(u32)FatCopies));	// Calculate the position of the Rootdirectory.
	 		FirstDataCluster	=   (u32)((u32)RootDirectory + ((u32)(PossibleRootEntries>>4)));					// Calculate the position of the first datacluster.
			CWD					= 	RootDirectory;																	// The actual directory is the rootdirectory.
			retvalue = 1;
		}
	}
	return(retvalue);	

}

  
  
//________________________________________________________________________________________________________________________________________
// Funtion: 	File * fopen_(u8*, u8 *);
// 
// Description:	This function looks for the file to be opened in the directory specified by the variable "CWD" of the drive. 
//				If the file was found this function returns a filepoiner to the opened file otherwise NULL//				
//
//	Return:		Pointer to the opened file or NULL
//				
//________________________________________________________________________________________________________________________________________

File * fopen_(s8 *fname, s8 mode)
{
	File *file;
	
	file = ReserveFilePointer();													// reserve a filepointer.	
	
	if(file != NULL)																// A free filepointer was found.
	{
		file->mode 	= mode;															// mode of fileoperation (read,write)

		if(SeekFileInDirectory(fname, file))										// if file was found
		{
			if(mode == 'a')															// open existing file for writing (append data at the end of the file)
			{	
				fseek_(file, 0, SEEK_END);											// fseek points to the end of the file
			}
		}		
		else
		{
			if((mode == 'a') || (mode == 'w'))										// specified file doesn't exist so create new file for writing data.
			{	
				if(CreateFileInDirectory(fname,file))								// Could an entry for the new file in the rootdirectory be created?
				{
					return(file);
				}	
				else
				{
					FreeFilePointer(file);										    // free the filepointer.
					file = NULL;
				}
			}
            else                                                                    // file with mode 'r' not found
            {
            	FreeFilePointer(file);												// free the filepointer.
                file = NULL;                                                        // file not found
            }
		}
	}
	return(file);
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	fflush_(File *file);
// 
// Description:	This function writes the data already in the buffer but not yet written to the file. 
//				
//________________________________________________________________________________________________________________________________________

s16	fflush_(File *file)
{
	u16 time=0;
	u16 date=0;

			
	if(file && ((file->mode =='a') || (file->mode =='w')))
	{
		if(file->byte_index > 0)															// has data been added to the file?		
		{
			SDC_PutSector((u32)(file->cluster_pointer + file->sector_index),file->buffer);// save the data still in the buffer 	
		}	
		SDC_GetSector((u32)file->directory_sector,file->buffer);							// read the directoryentry for this file.
		DirectoryEntry = (struct DirEntry *)file->buffer;
		DirectoryEntry[file->directory_index].size = (u32) file->filesize;
		DirectoryEntry[file->directory_index].time = (u16) time;
		DirectoryEntry[file->directory_index].date = (u16) date;
		SDC_PutSector((u32)file->directory_sector,file->buffer);
	}
	return(0);
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	fclose_(File *file);
// 
// Description:	This function closes the open file by writing the remaining data from the buffer to the device and entering the filesize 
//				in the directory entry.
//________________________________________________________________________________________________________________________________________

void fclose_(File *file)
{

	if(file != NULL)
	{
		fflush_(file);																		// save buffered data to the disk
	}
	FreeFilePointer(file);																	// and free the filepointer.
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	u32 fread_(void *buffer, s32 size, s32 count, File *file);
// 
// Description:	This function reads count objects of the specified size from the actual position of the file to the specified buffer.
//				
// Returnvalue: The function returns the number of objects (not bytes) read from the file.	
//				
//________________________________________________________________________________________________________________________________________

u32 fread_(void *buffer, u32 size, u32 count, File *file)
{
	u32 object_cnt 	= 0;															// count the number of objects read from the file.
	u32 object_size 	= 0;														// count the number of bytes read from the actual object.
	u8 *buff_pnt    = 0;															// a pointer to the actual bufferposition.
	u8 success      = 1;															// no error occured during read operation to the file.
	
	buff_pnt = (u8 *) buffer;														// cast the void pointer to an u8 *
	
	while((object_cnt < count) && success)
	{
		object_size = size;
		while((size > 0) && success)
		{
			*buff_pnt = (u8) fgetchar_(file);										// read a byte from the buffer to the opened file.
			buff_pnt++;
			size--;
		}
		if(success) object_cnt++;
	}		
	
	return(object_cnt);																// return the number of objects succesfully read from the file
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	u32 fwrite_(void *buffer, s32 size, s32 count, File *file);
// 
// Description:	This function writes count objects of the specified size from the buffer to the actual positon within the file.
//				
// Returnvalue: The function returns the number of objects (not bytes) written to the file.	
//				
//________________________________________________________________________________________________________________________________________

u32 fwrite_(void *buffer, u32 size, u32 count, File *file)
{
	u32 object_cnt 	= 0;															// count the number of objects written to the file.
	u32 object_size 	= 0;														// count the number of bytes written from the actual object.
	u8 *buff_pnt    = 0;															// a pointer to the actual bufferposition.
	u8 success      = 1;															// no error occured during write operation to the file.
	
	buff_pnt = (u8 *) buffer;														// cast the void pointer to an u8 *
	
	while((object_cnt < count) && success)
	{
		object_size = size;
		while((size > 0) && success)
		{
			success = fputchar_(file, *buff_pnt);									// write a byte from the buffer to the opened file.
			buff_pnt++;
			size--;
		}
		if(success) object_cnt++;
	}		
	
	return(object_cnt);																// return the number of objects succesfully written to the file
}																					// (!!!!! objects and not bytes !!!!)

//________________________________________________________________________________________________________________________________________
// Funtion: 	s16 fseek_(File *, s32, s16)
// 
// Description:	This function sets the pointer of the stream relative to the position 
//				specified by origin (SEEK_SET, SEEK_CUR, SEEK_END). 
//				
//________________________________________________________________________________________________________________________________________

s16 fseek_(File *file, s32 offset, s16 origin)
{
	s32			fposition 	= 0;
	s16 			retvalue 	= 1;
	u32 	temp 		= 0;
	
//......................................................
	if(origin == SEEK_SET)														// Fileposition relative to the beginning of the file.
	{
		fposition = 0;
	}	
//......................................................
	else if(origin == SEEK_END)													// Fileposition relative to the end of the file.
	{
		fposition  = (s32) file->filesize;
	}	
//......................................................
	else if(origin == SEEK_CUR)													// Fileposition relative to the current position of the file.
	{
		fposition = file->fileposition;
	}	

	fposition += offset;

	if((fposition >= 0) && (fposition <= (s32)file->filesize))				// is the pointer still within the file?
	{
		retvalue 				= 0;
		file->sector_index 		= 0;
		file->byte_index   		= 0;
		file->fileposition 		= 0;
		file->cluster_pointer 	= file->start_cluster;
		
		while(file->fileposition < fposition)
		{
			file->fileposition++;										
			if(file->byte_index < 511)									
			{
				file->byte_index++;
			}
			else
			{
				file->byte_index=0;												// reading at the beginning of new sector.
				file->sector_index++;											// continue reading in next sector
				if(file->sector_index >= SectorsPerCluster)					// When end of cluster is reached, the next datacluster has to be searched in the FAT.
				{
					if(file->fileposition < fposition) 
					{
						file->sector_index = 0;									// start reading new cluster at first sector of the cluster.
						GetNextCluster(file);									// Sets the clusterpointer of the file to the next datacluster.
					}
				}
			}	
		}
		if(file->byte_index)				
		{
			temp = (u32)((u32)file->cluster_pointer + (u32)file->sector_index);			
			SDC_GetSector((u32)temp,file->buffer);								// FileBuffer will be written at once at the end of the cluster and has to be updated.						
		}
	}	
	return(retvalue);
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	fgetchar_(File *file);
// 
// Description:	This function reads and returns one character from the specified file. 
//				
// Returnvalue: The function returns the character read from the specified memorylocation as u8 casted to s16 or EOF.
//________________________________________________________________________________________________________________________________________

s16 fgetchar_(File *file)
{	
	s16 c = EOF;
	u32 temp1;
	
	if(((file->fileposition)+1) < file->filesize)								// wen the end of the file is not reached, get the next character.
	{
		temp1  = (u32)file->cluster_pointer;									// calculate the adress of the next character to be read.
		temp1 += (u32)file->sector_index;			
	
		if(file->sector_in_buffer != temp1)									// Has the content of the buffer been modified and has to be updated?
		{
			SDC_GetSector((u32)temp1,file->buffer);							// Read the calculated cluster.			
			file->sector_in_buffer = (u32)temp1;
		}	
		c = (s16) file->buffer[file->byte_index];
		file->fileposition++;
	
		if(file->byte_index < 511)												// continue reading from this sector until the end of the sector is reached.
		{
			file->byte_index++;
		}
		else																	// has the end of an sector been reached->
		{
			file->byte_index=0;													// continue reading at the beginning -
			file->sector_index++;												// of new sector.
			if(file->sector_index >= SectorsPerCluster)						// When the end of an cluster is reached, the next datacluster has to be searched in the FAT.
			{
				file->sector_index = 0;											// start reading new cluster at first sector of the cluster.
				GetNextCluster(file);											// Sets the clusterpointer of the file to the next datacluster.
			}
		}
	}
	return(c);
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	fputchar_(File *file, s8 *);
// 
// Description:	This function writes a byte to the specified file and takes care of writing the necessary FAT- Entries. 
//				
// Returnvalue: The function returns a value of 0 if the data could not be written.
//________________________________________________________________________________________________________________________________________

u8 fputchar_(File *file,s8 c)
{	
	u32 ul_temp  = 0;
	u8 retvalue = 1;
	
    if(file->sector_index >= SectorsPerCluster)								// if end of the cluster is reached, find next free cluster
	{
		file->sector_index = 0;
		if(!AppendCluster(file)) retvalue = 0;									// append a new and free cluster at the end of the file.
	}

	file->buffer[file->byte_index] = c;										// write databyte into the buffer. The byte will be written to the device at once
	if(file->filesize == file->fileposition) file->filesize++;					// a character has been written to the file so the size is inkremented but only when the character has been added at the end of the file.
	file->fileposition++;														// the actual positon within the file. 
																				// if the buffer contains the complete sectordata.
	if(file->byte_index < 511)													// if the end of this sector is not reached yet
	{
		file->byte_index++;														// the next byte will be written to the next byteposition in this sector.
	}
	else																		// otherwise the data in the sectorbuffer will be written to the device and the next sector will be selected.
	{
		ul_temp  = (u32)file->cluster_pointer;
		ul_temp += (u32)file->sector_index;
		
		SDC_PutSector((u32)ul_temp,file->buffer);
		file->byte_index=0;														// and the next byte will be written at the beginning of this new sector.
		file->sector_index++;
		if(file->sector_index >= SectorsPerCluster)							// if end of the cluster is reached, find next free cluster
		{
			file->sector_index = 0;
			if(!AppendCluster(file)) retvalue = 0;								// append a new and free cluster at the end of the file.
		}
	}
	return(retvalue);
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	fputs_(File *file, s8 *string);
// 
// Description:	This function writes a zero terminated string to the specified file.
//				
//________________________________________________________________________________________________________________________________________

u8 fputs_(File *file,s8 * string)
{
	u8 i=0;
	
	while(string[i] != 0)
	{
		fputchar_(file,string[i]);
		i++;
	}
	return(0);
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	s8 * fgets_(s8 *string, s16 count, File *file)
// 
// Description:	This function reads a string from the file to the specifies string until EOF or end of line was detected.. 
//		
// Returnvalue: A pointer to the string or NULL if EOF was read from the file with no other characters before.
//________________________________________________________________________________________________________________________________________

s8 * fgets_(s8 *string, s16 count, File *file)
{
	s16 buff_pnt = 0;
	s16 buff_tmp = 0;
	s8 *retvalue = 0;
	
	retvalue = string;

	while(count > 1)												// read the count-1 characters from the file to the string.
	{
		buff_tmp = fgetchar_(file);									// read a character from the opened file.		
		if(buff_tmp == EOF) 										// is the end of the file reached, terminate the string with zero.
		{
			if(buff_pnt != 0)										// are there characters within the string?
			{
				break;
			}
			else
			{
				retvalue = NULL;									// first character read was EOF -> return(NULL);
				break;
			}
		}	
		else if(buff_tmp == 0x0A)									// lf detected.
		{		
			string[buff_pnt] = (s8) buff_tmp;						// add lf to the string.
			buff_pnt++;
			break;
		}
		else
		{
			string[buff_pnt] = (s8) buff_tmp;
			count--;
			buff_pnt++;
		}
	}
	string[buff_pnt] = 0;											// terminate string with zero
	return(string);
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	u8 fexist_(u8*);
// 
// Description:	This function searches the specified file and returns 0 if the file was not found.
//				
//
//	Return:		0 = file does not exist
//				1 = file exists
//________________________________________________________________________________________________________________________________________

u8 fexist_(s8 *fname)
{
	File *file;

	file = fopen_(fname,'r');										// try to open the specified file.
	
	if(file != NULL)
	{
		FreeFilePointer(file);  									// Free the filepoint												// free the filepointer
		return(1);													// file was found so return(1);
	}
	else
	{
		return(0);													// file not found return(0);
	}
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	GetNextCluster(File *file);
// 
// Description:	This function finds the next datacluster of the file specified with File *file. 
//				
// Returnvalue: The function returns "0" if the last cluster has already been reached.
//________________________________________________________________________________________________________________________________________

u16 GetNextCluster(File *file)
{
	u32 fat_pointer			=	0;
	u32 fat_sector_offset	=	0;
	u32 ul_tmp				=  	0;
	u8 retvalue				= 	0;													// no new cluster found yet.
	
	
	if((file->cluster_pointer >= RootDirectory) && (file->cluster_pointer < (RootDirectory + 31)))
	{																				// Is the next cluster searched within the rootdirectory and available?
		file->cluster_pointer++;													// the rootdirectory is a linear adress space of 32 clusters.
		retvalue = 1;																// and the next cluster has been found.
	}
	else if(file->cluster_pointer > (RootDirectory + 31))							// The specified cluster is within the FAT.
	{
		fat_sector_offset   = ((file->cluster_pointer) - (FirstDataCluster));		// Calculate index of actual cluster within the FAT.
		fat_sector_offset  /= SectorsPerCluster;									// calculate the index of the actual sector within the FAT. 					
		fat_sector_offset  += 2;													// In Fat16 clusterpositions have an offset of two.	
		fat_pointer = (fat_sector_offset%0x100);									// Calculate the sector within the cluster.																
		fat_sector_offset   = (fat_sector_offset>>8);								// and the position within the sector.

		SDC_GetSector((u32)(FileAllocationTable + fat_sector_offset),file->buffer);	
		file->sector_in_buffer = (FileAllocationTable + fat_sector_offset);		// Mark that new sector has been read.
	
		ul_tmp  = (u32)file->buffer[((fat_pointer << 1)+1)];						// Read next sector information from calculated clusterposition.
		ul_tmp  = (ul_tmp << 8);
		ul_tmp |= (u32)file->buffer[(fat_pointer << 1)];    
		ul_tmp -=2;																	// next datacluster is clusterposition in fat - 2.
		ul_tmp *= SectorsPerCluster;												// calculate sectorposition of new cluster
		ul_tmp += FirstDataCluster;													// in relation to first datacluster of the disk.
	
		if(ul_tmp < 0xfff7)															// has a new cluster been read or was the end of the fat reached?
		{
			file->cluster_pointer = (u32) ul_tmp;									// continue reading the file at the beginning of new datacluster.
			retvalue = 1;															// a new cluster was found.
		}	
	}
	return(retvalue);
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	u16 FindNextFreeCluster(void)
// 
// Description:	This function looks in the FAT to find the next free datacluster
//				
// Returnvalue: The function returns the adress of the next free cluster found within the fAT.
//________________________________________________________________________________________________________________________________________

u16 FindNextFreeCluster(File *file)
{
	u32 fat_pointer			=	0;													// Pointer to the first sector of the FAT.
	u32 ul_tmp				=  	0;													// temporary variable used to calculate a sectornumber.
	u16  fat_sector_offset	=	0;													// index to a sector within the FAT.
	u16  fat_entry			= 	0;													// index to an fatentry within the actual sector (256 fatentries are possible within one sector).
	u16  free_cluster			= 	0;												// a pointer to the first sector of the next free cluster.
	
	fat_pointer = (u32) FileAllocationTable;										// start searching for empty cluster at the beginning of the fat.
																					// if the end of the fat is not reached yet and no free cluster has been found
	while((fat_sector_offset < SectorsPerFat) && (!free_cluster))	
	{
		ul_tmp = (u32) ((u32)fat_pointer + (u32)fat_sector_offset);
		SDC_GetSector((u32)ul_tmp,file->buffer);									// read next sector of FAT.
		file->sector_in_buffer = ul_tmp;											// remember the number of the sector in FileBuffer.
		Fat = (struct FatEntry *)file->buffer;
		for(fat_entry=0;fat_entry<256;fat_entry++)									// look for an free cluster at all entries in this sector of the fat. 
		{
			if(Fat[fat_entry].next_cluster == 0x0000)								// empty cluster found!!
			{				
				Fat[fat_entry].next_cluster = 0xffff;								// mark this fat-entry as used and save it to the device.
				SDC_PutSector((u32)file->sector_in_buffer,file->buffer);
				free_cluster  = fat_entry;											// the relative position of the free cluster found in this sector of the FAT.
				free_cluster += (fat_sector_offset << 8);							// calculate the absolute position of the free cluster in the FAT;
				fat_entry = 256;													// terminate the search for a free cluster in this sector.
			}
		}
		fat_sector_offset++;									
	}	
return(free_cluster);
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	u16 AppendCluster(File *file);
// 
// Description:	This function finds the next free datacluster on the disk and appends it to the specified file.
//				
// Returnvalue: This funktion returns 1 if a cluster was appended to the specified file.
//________________________________________________________________________________________________________________________________________

u8 AppendCluster(File *file)
{
	u16  free_cluster = 0;														
	u32 fat_pointer	= 0;
	u8 retvalue    	= 0;
	
	free_cluster = FindNextFreeCluster(file);										// the next free cluster found on the disk.
	if(free_cluster) retvalue = 1;													// A free cluster was found and can be added to the end of the file. 
	fat_pointer  = FileAllocationTable;												// Set Pointer to the beginnig of the FAT.
	fat_pointer += (u32)((u32)GetFatClusterOffset(file) >> 8);						// find the sector in the FAT with 256 entries per sector.
	
    SDC_GetSector(fat_pointer,file->buffer);                                            
	Fat = (struct FatEntry *)file->buffer;
	Fat[GetFatSectorIndex(file)].next_cluster = free_cluster;						// append the free cluster to the end of the file in the FAT.
	SDC_PutSector((u32)fat_pointer,file->buffer);									// save the modified sector to the FAT.

	fat_pointer  = (u32)free_cluster;
	fat_pointer -= 2;
	fat_pointer *= SectorsPerCluster;
	fat_pointer += FirstDataCluster;

	file->cluster_pointer = fat_pointer;											// continue wrtiting to the file in the new and free datacluster.
	return(retvalue);																// return 1 when a new cluster was appended to the file
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	void DeleteClusterChain(u16 startcluster);
// 
// Description:	This function frees all the clusters used for file from the fat.
//				
// Returnvalue: none
//________________________________________________________________________________________________________________________________________

void DeleteClusterChain(u16 startcluster)
{
	u16 fat_index			=	0;
	u16 fat_sector_offset	=	0;
	u32 sector_in_buffer	=	0;	
	u32 ul_temp				= 	0;
	u8 buffer[512];
	
	
	fat_index = (startcluster % 0x100);												// Calculate the sector within the cluster.																
	fat_sector_offset = (startcluster >> 8);										// and the position within the sector.
	ul_temp = (u32)(FileAllocationTable + fat_sector_offset);
		
	
	do
	{
		if(sector_in_buffer != ul_temp)
		{
			sector_in_buffer = ul_temp;
			SDC_GetSector(ul_temp,buffer);	
		}
		Fat = (struct FatEntry *)buffer; 
	
		startcluster = Fat[fat_index].next_cluster;
		Fat[fat_index].next_cluster = 0x0000;										// free the cluster within the fat.

		if(startcluster != 0xffff)													// if file had only one cluster
		{
			fat_index = (startcluster % 0x100);										// Calculate the sector within the cluster.																
			fat_sector_offset = (startcluster >> 8);								// and the position within the sector.
			ul_temp = (u32)(FileAllocationTable + fat_sector_offset);
			if((sector_in_buffer != ul_temp) || (startcluster == 0xffff))
			{
				SDC_PutSector(sector_in_buffer,buffer);	
			}
		}
	}
	while(startcluster != 0xffff);													// last cluster has been deleted.
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	u16 GetFatClusterIndex(File *file);
// 
// Description:	This function returns the clusterindex of the cluster specified by file->cluster_pointer of the specified file.
//				
//________________________________________________________________________________________________________________________________________

u16 GetFatClusterOffset(File *file)
{
	u32 fat_sector_offset	=	0;

	fat_sector_offset   = ((file->cluster_pointer) - (FirstDataCluster));			// Calculate index of actual cluster in FAT.
	fat_sector_offset  /= SectorsPerCluster;														
	fat_sector_offset  += 2;														// In Fat16 clusterpositions have an offset of two.								
	
	return((u16)fat_sector_offset);
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	u16 GetFatSectorIndex(File *file);
// 
// Description:	This function returns the sectorindex of the cluster specified by file->cluster_pointer of the specified file.
//				
//________________________________________________________________________________________________________________________________________

u16 GetFatSectorIndex(File *file)
{
	u16 fat_pointer			=	0;
	
	fat_pointer = GetFatClusterOffset(file);
	fat_pointer = fat_pointer % 0x100;												// Calculate the clusterposition in the fat																
	
	return(fat_pointer);
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	u16 CreateFileInDirectory(u8 *, File *)
// 
// Description:	This function looks for the next free position in the directory and creates an entry. The type of an directoryentry is
//				specified by the attribute. 
//				bit0:	unused
//				bit1:	archive
//				bit2:	read_only
//				bit3:	system  
//				bit4:	directory
//				bit5:	volume
//________________________________________________________________________________________________________________________________________

u8 CreateFileInDirectory(s8 *fname, File *file)
{
	u16 	rootentry	= 0;														// index to an entry in the rootdirectory.
	u16 	cnt_enries_searched = 0;												// count the number of rootentries which have been searched already.
	u8 		i = 0;
	u16 	sector_offset = 0;														// index to the sector of the Rootentry which is searched momentarily
	u8 		retvalue = 0;
	u32		cluster_temp = 0;
	u16		cluster = 0;
	s8 name[11] 	= "           ";			

	SeperateFileName(fname,name);

	cluster_temp = (u32)FindNextFreeCluster(file);									// the next free cluster on the disk.
	
	if(cluster_temp) 																// if a free cluster is available:
	{
		cluster = (u16)cluster_temp;												// remember the index of the free datacluster found for the directory entry.
		cluster_temp -=2;															// Clusterposition is ((position in FAT)-2). first two entries in FAT are reserved.
		cluster_temp *= SectorsPerCluster;											// Calculate relative sectorindex of first datacluster.
		file->start_cluster   = (FirstDataCluster + cluster_temp);					// Calculate absolute sectorposition of first datacluster.
		file->cluster_pointer = file->start_cluster;								// start reading the file with the first sector of the first datacluster.
	
																					// directory starts at sector specified by dir_sector. This can be the rootdirectory or any other directory.
		do
		{																			// search the next 16 rootentries in this sector of the roordirectory.
			rootentry=0;									
			SDC_GetSector((u32)(CWD + sector_offset),file->buffer);				// Read the Rootdirectory.
			DirectoryEntry = (struct DirEntry *)file->buffer;
			while((rootentry<16) && (!retvalue))
			{
				if((DirectoryEntry[rootentry].attribute == 0) || (DirectoryEntry[rootentry].attribute == 0xE5))	// empty directory entry found
				{
					for(i=0;i<11;i++) DirectoryEntry[rootentry].name[i] = name[i];// Kopie the filename and the file extension to the directoryentry.
					DirectoryEntry[rootentry].attribute    = _FILE;					// Set the fileattribute to archive to reserve the directoryentry.
					DirectoryEntry[rootentry].startcluster = cluster;				// copy the location of the first datacluster to the directoryentry.
					DirectoryEntry[rootentry].size     = 0;							// the new createted file has no content yet.
					file->directory_sector = (u32) (CWD + sector_offset);
					file->directory_index  = (u8) rootentry;
					retvalue = 1;
					SDC_PutSector((u32)(CWD + sector_offset),file->buffer);				
				}			
				rootentry++;
				cnt_enries_searched++;
			}
			if(!retvalue)															// file not found in this sector so take next sector.
			{
				rootentry = 0;
				sector_offset++;
			}
		}
		while((cnt_enries_searched< PossibleRootEntries) && (!retvalue));

	}
	return(retvalue);																// return 1 if file has been created otherwise return 0.
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	u16 SeekFileInDirectory(s8 *fname, File *)
// 
// Description:	this function searches all possible entries withint the actual directory for the specified object.
//				
// Returnvalue: This function returns 1 if the directoryentry specified was found.
//________________________________________________________________________________________________________________________________________

u8 SeekFileInDirectory(s8 *fname, File *file)
{
	u16 	rootentry=0;
	u16   	end_of_directory_not_reached = 0;										// the directory has been read completely without a result.
	u8 		i=0;
	u8  	retvalue = 0;
	u32  	cluster_temp = 0;
	s8 name[11] 	= "           ";			
	
	SeperateFileName(fname,name);
	
	file->cluster_pointer = CWD;													// start looking for the file in the actual directory.

																					// directory starts at sector specified by dir_sector. This can be the rootdirectory or any other directory.
	do
	{																				// search the next 16 rootentries in this sector of the roordirectory.
		rootentry=0;									
		SDC_GetSector((u32) file->cluster_pointer,file->buffer);					// Read the Rootdirectory.
		DirectoryEntry = (struct DirEntry *)file->buffer;

		while((!retvalue)&&(rootentry<16))
		{
			i=0;
			if(DirectoryEntry[rootentry].name[0] != 0xe5)							// ignore deleted items.
			{
				while((i<=10)&&(DirectoryEntry[rootentry].name[i] == name[i]))
				{
					i++;
				}
			}

			if((i==11) && (DirectoryEntry[rootentry].attribute & _FILE))			// entry found!! -> reading startcluster of entry from offset 26.
			{
				cluster_temp = (u32)DirectoryEntry[rootentry].startcluster; 							
				cluster_temp -=2;													// Clusterposition is ((position in FAT)-2). first two entries in FAT are reserved.
				cluster_temp *= (u32)SectorsPerCluster;								// Calculate positon of first cluster.
				file->start_cluster   = (FirstDataCluster + cluster_temp);
				file->directory_sector = (u32) file->cluster_pointer;
				file->cluster_pointer = file->start_cluster;						// start reading the file with the first cluster.
				file->filesize = (u32) DirectoryEntry[rootentry].size;
				file->directory_index  = (u8) rootentry;
				retvalue = 1;
			}
			rootentry++;
		}
		if(!retvalue)																// file not found in this sector so take next sector.
		{
			end_of_directory_not_reached = GetNextCluster(file);
		}
	}
	while((end_of_directory_not_reached) && (!retvalue));
	return(retvalue);
}



//________________________________________________________________________________________________________________________________________
// Funtion: 	void SeperateFileName(u8*);
// 
// Description:	This function seperates the filename and the fileattribute and brings them into the needed format ('test.txt' -> 'TEST    TXT');
//				
//________________________________________________________________________________________________________________________________________

void SeperateFileName(s8 *fname, s8 *name)
{
	u8 readpointer	= 0;
	u8 writepointer	= 0;
	u8 attribute	= 1;
	u8 i = 0;
	
	
	while((writepointer<=10) && (fname[readpointer]!=0))							// the rootdirectoryentry is 8bytes for filename and 3bytes for fileattribute.
	{																				// the filename in the rootdirectory is in the format "TEST    TXT" without the dot.
		if(fname[readpointer]=='.')												// seperating filename and attribute.
		{
			if(attribute)															// is the filename "." or ".." ?
			{
				name[writepointer] = fname[readpointer];
				readpointer++;
				writepointer++;			
			}
			else
			{
				if(fname[(readpointer-1)] != '*')
				{
					for(i=writepointer;i<8;i++)
					{
						name[i] = ' ';
					}
				}
				readpointer++;
				writepointer = 8;
			}
		}
		else if(fname[readpointer] == '*')											// wildcard found within the filename + extension.
		{
			if(writepointer < 8)													// in extension.
			{
				readpointer++;
				writepointer = 8;					
			}
			else																	// in filename.
			{
				writepointer = 11;													// jump to the end of the string to terminate this function.
			}
			attribute = 0;
		}
		else
		{
			if((fname[readpointer]>96) && (fname[readpointer]<123))
			{
				name[writepointer]=(fname[readpointer] - 32);						// all characters must be upper case.
			}
			else
			{
				name[writepointer]=fname[readpointer];
			}	
			readpointer++;
			writepointer++;
			attribute = 0;
		}
	}	
}

//________________________________________________________________________________________________________________________________________
// Funtion: 	File * ReserveFilePointer_(void);
// 
// Description:	This function looks for a free filepointer and reserves it.
//				
//
//	Return:		NULL = faild to reserve a filepointer
// 				otherwise filepointer
//________________________________________________________________________________________________________________________________________

File * ReserveFilePointer(void)
{
	File *file;
	file = NULL;
	u8	temp;
	
	for(temp = 0;temp<__MAX_FILES_USED;temp++)
	{
		if(FilePointer[temp].state == _UNUSED)										// free filepointer found?
		{
			file = &FilePointer[temp];
			FilePointer[temp].state 				= _USED;						// mark as used.
			FilePointer[temp].mode 					= 0;							// type of access (read/write) not defined yet.
			FilePointer[temp].start_cluster			= 0;							// Sectorpointer to the first sector of the first datacluster of the file. 
			FilePointer[temp].cluster_pointer		= 0;							// Pointer to the cluster which is edited at the moment.
			FilePointer[temp].sector_index 			= 0;							// The sector which is edited at the moment (cluster_pointer + sector_index).
			FilePointer[temp].byte_index 			= 0;							// The bytelocation within the current sector (cluster_pointer + sector_index + byte_index).
			FilePointer[temp].filesize 				= 0;							// the size of the opend file in bytes.
			FilePointer[temp].fileposition 			= 0;							// pointer to a character within the file 0 < fileposition < filesize
			FilePointer[temp].sector_in_buffer 		= 0;							// the last sector read, wich is still in the sectorbuffer.
			FilePointer[temp].directory_sector 		= 0;							// the sectorposition where the directoryentry has been made.
			FilePointer[temp].directory_index 		= 0;							// the index to the directoryentry within the specified sector.
			FilePointer[temp].attribute 			= 0;							// the attribute of the file opened.
			break;
		}
	}
	return(file);
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	void FreeFilePointer_(File *);
// 
// Description:	This function free's the filepointer by marking it as unused.
//				
//
//	Return:		none
// 				
//________________________________________________________________________________________________________________________________________

void FreeFilePointer(File *file)
{
	u8 cnt = 0;
	
	for(cnt=0;cnt<__MAX_FILES_USED;cnt++)											// Is the filepointeradress vaild?
	{
		if(&FilePointer[cnt] == file)												// filepointer found therefore it must be valid
		{
			FilePointer[cnt].state = _UNUSED;										// and can be marked as unused.
		}
	}
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	void DelteDirectoryEntry(Find *)
// 
// Description:	This function deletes the directoryentry of the specified item.
//				
//				
// returnvalue: 1 if the directory could be created.
//________________________________________________________________________________________________________________________________________

void DeleteDirectoryEntry(Find *item)
{
	u8 buffer[512];
	
	
	SDC_GetSector((u32) item->cluster_pointer,buffer);								// Read the Rootdirectory.
	DirectoryEntry = (struct DirEntry *)buffer;

	DirectoryEntry[(item->directory_index)-1].attribute = 0;						// free the directoryentry.
	DirectoryEntry[(item->directory_index)-1].name[0] = 0xE5;						// free the directoryentry.
	SDC_PutSector((u32) item->cluster_pointer,buffer);								// Read the Rootdirectory.
}




//________________________________________________________________________________________________________________________________________
// Funtion: 	u8 CreateSubDirectory(u8 *)
// 
// Description:	This function creates an directory within the directory specified by CWD
//				
//				
// returnvalue: 1 if the directory could be created.
//________________________________________________________________________________________________________________________________________

u8 CreateSubDirectory(s8 *fname)
{
	u16 	index	= 0;															// index to an entry in the rootdirectory.
	u16 	cnt_entries_searched = 0;												// count the number of rootentries which have been searched already.
	u16		i = 0;
	u16 	sector_offset = 0;														// index to the sector of the entry which is searched momentarily
	u8 		retvalue = 0;
	u32		cluster_temp = 0;
	u16		cluster = 0;
	File 	file;
	s8		name[11] = {"           "};

	SeperateFileName(fname,name);
	cluster_temp = (u32)FindNextFreeCluster(&file);								// the next free cluster on the disk.
	
	if(cluster_temp) 																// if a free cluster is available:
	{
		cluster = (u16)cluster_temp;												// remember the index of the free datacluster found for the directory entry.
		cluster_temp -=2;															// Clusterposition is ((position in FAT)-2). first two entries in FAT are reserved.
		cluster_temp *= SectorsPerCluster;											// Calculate relative sectorindex of first datacluster.
		file.start_cluster   = (FirstDataCluster + cluster_temp);					// Calculate absolute sectorposition of first datacluster.
		file.cluster_pointer = file.start_cluster;									// start reading the file with the first sector of the first datacluster.
	
// -Initialise new cluster to zero--------------------------------------------------------
		for(i=0;i<512;i++)
		{
			file.buffer[i] = 0;														// initialise buffer to zero
		}
		for(sector_offset=0;sector_offset<SectorsPerCluster;sector_offset++)		// initialise all sectors of new cluster with buffer.
		{
			SDC_PutSector((u32)(file.start_cluster + sector_offset),file.buffer);	// save the initialised sector to the card.	
		}
// -Create directoryentry "." -------------------------------------------------------------
		DirectoryEntry = (struct DirEntry *)file.buffer;
		DirectoryEntry[0].name[0] = '.';									
		DirectoryEntry[0].attribute = _DIRECTORY;							
		DirectoryEntry[0].startcluster = cluster;									
// -Create directoryentry "." -------------------------------------------------------------
		DirectoryEntry[1].name[0] = '.';									
		DirectoryEntry[1].name[1] = '.';									
		DirectoryEntry[1].attribute = _DIRECTORY;							
		if(CWD == RootDirectory)
		{
			DirectoryEntry[1].startcluster = 0;											
		}
		else
		{
			cluster_temp = (CWD - FirstDataCluster);
			cluster_temp /= SectorsPerCluster;
			cluster_temp -= 2;
			DirectoryEntry[1].startcluster = (u16) cluster_temp;													
		}
		SDC_PutSector((u32) file.start_cluster,file.buffer);						// save the initialised sector to the card.	
// -create directoryentry within the cwd --------------------------------------------------
		sector_offset = 0;
		cnt_entries_searched = 0;
		do
		{																			// search the next 16 rootentries in this sector of the roordirectory.
			index=0;									
			SDC_GetSector((u32)(CWD + sector_offset),file.buffer);					// Read the actual directory.
			DirectoryEntry = (struct DirEntry *)file.buffer;
			while((index<16) && (!retvalue))
			{
				if((DirectoryEntry[index].attribute == 0) || (DirectoryEntry[index].attribute == 0xE5))	// empty directory entry found
				{
					for(i=0;i<11;i++) DirectoryEntry[index].name[i] = name[i];	// Kopie the filename and the file extension to the directoryentry.
					DirectoryEntry[index].attribute    = _DIRECTORY;				// Set the fileattribute to archive to reserve the directoryentry.
					DirectoryEntry[index].startcluster = cluster;					// copy the location of the first datacluster to the directoryentry.
					DirectoryEntry[index].size     = 0;								// the new createted file has no content yet.
					file.directory_sector = (u32) (CWD + sector_offset);
					file.directory_index  = (u8) index;
					retvalue = 1;
					SDC_PutSector((u32)(CWD + sector_offset),file.buffer);				
				}			
				index++;
				cnt_entries_searched++;
			}
			if(!retvalue)															// file not found in this sector so take next sector.
			{
				index = 0;
				sector_offset++;
			}
		}
		while((cnt_entries_searched< PossibleRootEntries) && (!retvalue));

	}
	return(retvalue);																// return 1 if file has been created otherwise return 0.
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	u16 SeekSubDirectory(s8 *fname)
// 
// Description:	looks for the specified directory within the CWD.
//				
// Returnvalue: If the specified directory was found the startcluster is returned. otherwise 0.
//________________________________________________________________________________________________________________________________________

u16 SeekSubDirectory(s8 *fname)
{
	u16 	index = 0;
	u16   	end_of_directory_not_reached = 0;										// the directory has been read completely without a result.
	u8 		i = 0;
	u16  	cluster_temp = 0;
	s8 name[11] 	= "           ";			
	File 	file;

	SeperateFileName(fname,name);
	
	file.cluster_pointer = CWD;														// start looking for the file in the actual directory.
	file.start_cluster   = CWD;														// start looking for the file in the actual directory.

																					// directory starts at sector specified by dir_sector. This can be the rootdirectory or any other directory.
	do
	{																				// search the next 16 rootentries in this sector of the roordirectory.		
		index=0;									
		SDC_GetSector((u32) file.cluster_pointer,file.buffer);						// Read the Rootdirectory.
		DirectoryEntry = (struct DirEntry *)file.buffer;

		while((!cluster_temp)&&(index<16))
		{
			i=0;
			if(DirectoryEntry[index].name[0] != 0xe5)								// ignore deleted items.
			{
				while((i<=10)&&(DirectoryEntry[index].name[i] == name[i]))
				{
					i++;
				}
			}

			if((i==11) && (DirectoryEntry[index].attribute & _DIRECTORY))			// entry found!! -> reading startcluster of entry from offset 26.
			{
				cluster_temp = (u16)DirectoryEntry[index].startcluster; 							
			}
			index++;
		}
		if(!cluster_temp)															// file not found in this sector so take next sector.
		{
			end_of_directory_not_reached = GetNextCluster(&file);
		}
	}
	while((end_of_directory_not_reached) && (!cluster_temp));
	return(cluster_temp);
}



//________________________________________________________________________________________________________________________________________
// Funtion: 	u8 mkdir_(u8 *)
// 
// Description:	This function checks if the directory to be created already exists. If not the directory will be created.
//				
//				
// returnvalue: 1 if the directory could be created.
//________________________________________________________________________________________________________________________________________

u8	mkdir_(s8 *fname)
{
	u8 retvalue = 0;
	
	retvalue = SeekSubDirectory(fname);												// check wether the specified directory already exists.
	
	if(!retvalue)
	{
		CreateSubDirectory(fname);													// if directory doesn't exist, create it.
		retvalue = 1;
	}
	else
	{
		retvalue = 0;
	}
	
	return(retvalue);
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	u8 chdir_(u8 *)
// 
// Description:	This function changes the CWD to the directory specified.
//				
//				
// returnvalue: 1 if the directory could be changed.
//________________________________________________________________________________________________________________________________________

u8	chdir_(s8 *fname) 
{
	u8 	retvalue = 0;
	s8  name[11] = {"           "};
	
	u32 ultemp = 0;

	SeperateFileName(fname,name);	
	
	ultemp = (u32)SeekSubDirectory(name);
	if(ultemp >= 2)
	{
		ultemp -=2;																	// Clusterposition is ((position in FAT)-2). first two entries in FAT are reserved.
		ultemp *= SectorsPerCluster;												// Calculate relative sectorindex of first datacluster.
		ultemp += FirstDataCluster;
		CWD = ultemp;
		retvalue = 1;
	}
	else
	{
		CWD = RootDirectory;
		retvalue = 1;
	}

	return(retvalue);
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	u8 FindItem(s8 *fname, Find *)
// 
// Description:	finds an item (file or directory) within common working directory (cwd). Wildcards '*' or '?' will be considered.
//				
// Returnvalue: If an item was found this function returns '1' else '0'.
//________________________________________________________________________________________________________________________________________

u8 FindItem(Find *item)
{
	u16 	index = 0;
	u16   	end_of_directory_not_reached = 0;										// the directory has been read completely without a result.
	u8 		i = 0;
	u8		readpointer = 0;
	u8		writepointer = 0;
	u8		retvalue = 0;
	File 	file;

	
	file.cluster_pointer = item->cluster_pointer;
	file.start_cluster   = item->cluster_pointer;					
	index 				 = item->directory_index;
																					// directory starts at sector specified by dir_sector. This can be the rootdirectory or any other directory.
	do
	{																				// search the next 16 rootentries in this sector of the roordirectory.		
		SDC_GetSector((u32) file.cluster_pointer,file.buffer);						// Read the Rootdirectory.
		DirectoryEntry = (struct DirEntry *)file.buffer;

		while((!retvalue)&&(index<16))
		{
			i=0;			
			if(DirectoryEntry[index].name[0] != 0xe5)								// ignore deleted items.
			{
				while((i<=10)&&((DirectoryEntry[index].name[i] == item->searchstring[i]) || (item->searchstring[i]=='*') || item->searchstring[i]=='?'))
				{
					i++;
				}
			}

			if((i==11) && (DirectoryEntry[index].attribute & item->attribute))
			{
				for(readpointer=0;readpointer<=10;readpointer++)
				{
					if(DirectoryEntry[index].name[readpointer] != ' ')
					{
						item->name[writepointer] = DirectoryEntry[index].name[readpointer];	// copy the name of the item found to the find_structure.
						writepointer++;
					}
					else if((readpointer==7) && (DirectoryEntry[index].attribute == _FILE))	// if the item found is a file
					{
						if(DirectoryEntry[index].name[readpointer] != ' ')
						{
							item->name[writepointer] = DirectoryEntry[index].name[readpointer];	// copy the name of the item found to the find_structure.
							writepointer++;
						}
						item->name[writepointer] = '.';							// then seperate the name and the extension by a '.' at index 8.						
						writepointer++;
					}
				}
				item->startcluster = (u16)DirectoryEntry[index].startcluster; 							
				item->directory_index = ++index;
				item->cluster_pointer = file.cluster_pointer;
				retvalue = 1;
			}
			index++;
		}
		if(!retvalue)																// file not found in this sector so take next sector.
		{
			end_of_directory_not_reached = GetNextCluster(&file);
		}
		index = 0;
	}
	while((end_of_directory_not_reached) && (!retvalue));
	
	return(retvalue);	
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	u8 findfirst(s8 *fname, Find *)
// 
// Description:	finds the first item (file or directory) within common working directory (cwd). Wildcards '*' or '?' will be considered.
//				
// Returnvalue: If an item was found this function returns '1' else '0'.
//________________________________________________________________________________________________________________________________________

u8 findfirst_(s8 *fname, Find *item, u8 attribute)
{
	u8 retvalue = 0;
	u8 i = 0;

	for(i=0;i<=11;i++)
	{
		item->searchstring[i] = '*';												// initialise the searchstring with wildcards.
		item->name[i] = 0;
	}

	SeperateFileName(fname,item->searchstring);
	
	item->cluster_pointer = CWD;													// findfirst_ starts at the beginning of the cwd.
	item->directory_index = 0;
	item->attribute = attribute;
	
	retvalue = FindItem(item);

	return(retvalue);	
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	u8 findnext(Find *)
// 
// Description:	finds the first item (file or directory) within common working directory (cwd). Wildcards '*' or '?' will be considered.
//				
// Returnvalue: If an item was found this function returns '1' else '0'.
//________________________________________________________________________________________________________________________________________

u8 findnext_(Find *item)
{
	u8 retvalue = 0;
	u8 i = 0;

	for(i=0;i<=11;i++)																// copy the name of the searched item to the findstructure.
	{
		item->name[i] = 0;
	}

	retvalue = FindItem(item);														// search the item.

	return(retvalue);	
}



//________________________________________________________________________________________________________________________________________
// Funtion: 	u8 fdelete(s8 *fname)
// 
// Description:	Deletes the file specified by fname.
//				
// Returnvalue: 
//________________________________________________________________________________________________________________________________________

u8 fdelete_(s8 *fname)
{
	u8 retvalue = 0;
	Find item;
	
	retvalue = findfirst_(fname,&item, _FILE);										// look for the item to be deleted.

	if(retvalue);																	// item found?
	{
		if(item.startcluster)														// files containing no data often don't reserve clusters.
		{
			DeleteClusterChain(item.startcluster);									// delete all fatentries of the item. 
		}
		DeleteDirectoryEntry(&item);												// free the directoryentry.
	
		do
		{
			retvalue = findnext_(&item);
			if(retvalue)
			{
				DeleteClusterChain(item.startcluster);								// delete all fatentries of the item. 
				DeleteDirectoryEntry(&item);										// free the directoryentry.				
			}
		}
		while(retvalue);	
	}

	return(retvalue);	
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	u8 rmdir(s8 *fname)
// 
// Description:	Deletes the directory specified by dname.
//				
// Returnvalue: 
//________________________________________________________________________________________________________________________________________

u8 rmdir_(s8 *dname)
{
	u8 retvalue = 0;
	Find item;
	
	retvalue = findfirst_(dname,&item, _DIRECTORY);									// look for the item to be deleted.

	if(retvalue);																		// item found?
	{
		DeleteClusterChain(item.startcluster);											// delete all fatentries of the item. 
		DeleteDirectoryEntry(&item);													// free the directoryentry.
	
		do
		{
			retvalue = findnext_(&item);
			if(retvalue)
			{
				DeleteClusterChain(item.startcluster);									// delete all fatentries of the item. 
				DeleteDirectoryEntry(&item);											// free the directoryentry.				
			}
		}
		while(retvalue);	
	}

	return(retvalue);	
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	u16 feof_(File *file)
// 
// Description:	This function checks wether the end of the file has been reached.
//				
// Returnvalue: 0 if the end of the file was not reached otherwise 1. 
//________________________________________________________________________________________________________________________________________

u16 feof_(File *file)
{	
	if(((file->fileposition)+1) < (file->filesize))
	{
		return(0);
	}
	else 
	{
		return(1);	
	}
}
