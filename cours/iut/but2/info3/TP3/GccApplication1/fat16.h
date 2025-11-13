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

#ifndef __fat16_h
#define __fat16_h
#include "datatypes.h"



//________________________________________________________________________________________________________________________________________
// 
// Userspecific definitions
//				
//________________________________________________________________________________________________________________________________________

#define		__MAX_FILES_USED	1	// The number of files that can be opened simultaneously. 


//________________________________________________________________________________________________________________________________________
// 
// Structure of a filepointer
//				
//________________________________________________________________________________________________________________________________________

#define		_UNUSED		1		// Bits used in the attribute of an directory entry.
#define		_USED		2
#define		_ARCHIVE	2
#define		_READ_ONLY	4
#define		_SYSTEM		8
#define		_DIRECTORY	16
#define		_FILE		32


typedef struct afile
{
	u32 start_cluster;				// Sectorpointer to the first sector of the first datacluster of the file. 
	u32 cluster_pointer;			// Pointer to the cluster which is edited at the moment.
	u8	sector_index;				// The sector which is edited at the moment (cluster_pointer + sector_index).
	u16 byte_index;					// The bytelocation within the current sector (cluster_pointer + sector_index + byte_index).
	u8	mode;						// mode of fileoperation (read,write)
	u32 filesize;					// the size of the opend file in bytes.
	u32 fileposition;				// pointer to a character within the file 0 < fileposition < filesize
	u32 sector_in_buffer;			// the last sector read, wich is still in the sectorbuffer.
	u32 directory_root_sector;		// pointer to the root of the 
	u32 directory_sector;			// the sectorposition where the directoryentry has been made.
	u8 	directory_index;			// the index to the directoryentry within the specified sector.
	u8 	attribute;					// the attribute of the file opened.
	u8  buffer[512];				// Buffer for read and write operation from or to the mmc.
	u8	state;						// state of the filepointer (used/unused/...) 
} File;

//________________________________________________________________________________________________________________________________________
// 
// Structure of an item to find within the cwd
//				
//________________________________________________________________________________________________________________________________________

typedef struct find
{
	s8	name[12];					// filename + extension or directoryname of the item found within the cwd.
	s8  searchstring[13];
	u32 cluster_pointer;			// Sectorpointer to the sector of the item searched within the cwd.
	u16	startcluster;				// pointer to the first datacluster of the item found in the cwd.
	u32 filesize;					// the size of the opend file in bytes.
	u32 directory_sector;			// the sector within the actual cluster where the directoryentry was found.
	u8 	directory_index;			// the index to the directoryentry within the specified sector.
	u8 	attribute;					// the attribute of the file opened.
} Find;

//________________________________________________________________________________________________________________________________________
// 
// Directoryentries
//				
//________________________________________________________________________________________________________________________________________


struct DirEntry
{
	u8   name[8];					// 8 bytes name.
	u8   extension[3];				// 3 bytes extension.
	u8   attribute;					// attribute of the directory entry (unused,archive,read-only,system,directory,volume)
	u8   reserved[10];				// reserved bytes within the directory entry.
	u16  time;						// time and
	u16  date;						// date of last write acces to the file or directory.
	u16  startcluster;				// first cluster of the file or directory.
	u32  size;						// size of the file or directory in bytes.
} __attribute__((packed));

//________________________________________________________________________________________________________________________________________
// 
// Structure of an entry within the fileallocationtable.
//				
//________________________________________________________________________________________________________________________________________

struct FatEntry
{
	u16  next_cluster;				// the next cluster of the file.
}  __attribute__((packed)); 

//________________________________________________________________________________________________________________________________________
// 
// Partitions
//				
//________________________________________________________________________________________________________________________________________

#define	_EMPTY							0x00   
#define	_FAT12							0x01 
#define	_FAT16_ST_32_MB					0x04 
#define	_EXTENDED						0x05 
#define	_FAT16_LT_32_MB					0x06 
#define	_HPFS							0x07 
#define	_FAT32 							0x0B 
#define	_FAT32_BIOS_Extension 			0x0C 
#define	_FAT16_32_MB_BIOS_Extension		0x0E 
#define	_EXTENDED_BIOS_Extension		0x0F 
#define	_EISA							0x12 
#define	_DYNAMIC						0x42 
#define	_Linux_Swap						0x82 
#define	_Linux_Native 					0x83 
#define	_Linux_LVM 						0x8E 
#define	_FreeBSD 						0xA5 
#define	_OpenBSD 						0xA6 
#define	_NetBSD 						0xA9 


struct PartitionEntry
{
	u8	PartitionState;
	u8	BeginningHead;
	u16	BeginningCylinder;
	u8	Type;
	u8	EndHead;
	u16	EndCylinder;
	u32	NoSectorsBeforePartition;
	u32	NoSectorsPartition	;
} __attribute__((packed)); 


//________________________________________________________________________________________________________________________________________
// 
// Structure of the VolumeBootRecord
//				
//________________________________________________________________________________________________________________________________________

struct VBR_Entry
{
	u8  dummy[11];						
	u16 bps;
	u8  SectorsPerCluster;
	u16 ReservedSectors;
	u8  NoFATCopies;
	u16 MaxRootEntries;
	u16 dummy2;
	u8  dummy3;
	u16 SectorsPerFAT;
} __attribute__((packed)); 

//________________________________________________________________________________________________________________________________________
// 
// Structure of the MasterBootRecord
//				
//________________________________________________________________________________________________________________________________________

#define		_MBR_SECTOR	0		// The MasterBootRecord is located in sector 0

struct MBR_Entry
{
	u8  ExecutableCode[446];						
	struct 	PartitionEntry	PartitionEntry1;						
	struct 	PartitionEntry	PartitionEntry2;						
	struct 	PartitionEntry	PartitionEntry3;						
	struct 	PartitionEntry	PartitionEntry4;						
	u16		ExecutableMarker;	
} __attribute__((packed)); 

//________________________________________________________________________________________________________________________________________
// 
// API to the FAT16 filesystem
//				
//________________________________________________________________________________________________________________________________________

extern u8		InitFat16(void);		
extern File *	fopen_(s8 *fname,s8 mode);
extern s16		fflush_(File *file);
extern void 	fclose_(File *file);
extern u32 		fread_(void *buffer, u32 size, u32 count, File *file); 
extern u32 		fwrite_(void *buffer, u32 size, u32 count, File *file);
extern s16  	fseek_(File *file, s32 offset, s16 origin);
extern s16 		fgetchar_(File *file);
extern u8		fputchar_(File *file,s8 c);
extern u8		fputs_(File *file,s8 *string);
extern s8 *  	fgets_(s8 *s, s16 count, File *file);
extern s16		frename_(s8 *oldname, s8 *newname);
extern u8 		fexist_(s8 *fname);
extern u8		mkdir_(s8 *fname);
extern u8		chdir_(s8 *fname);
extern u8		findfirst_(s8 *fname, Find *item, u8 attribute);
extern u8		findnext_(Find *item);
extern u16		feof_(File *);

//________________________________________________________________________________________________________________________________________
// 
// Functions needed internaly for the fat16 implementation 
//				
//________________________________________________________________________________________________________________________________________

extern u8		SeekFileInDirectory(s8*fname, File *file);
extern u8		CreateFileInDirectory(s8*fname, File *file);
extern u16 		FindNextFreeCluster(File *file);
extern void 	SeperateFileName(s8*fname, s8*name);
extern u8 		ScanSubDirectories(s8*fname, File *file);
extern u16   	GetNextCluster(File *file);
extern u8 		AppendCluster(File *file);
extern u16 		GetFatClusterOffset(File *file);
extern u16 		GetFatSectorIndex(File *file);
extern File * 	ReserveFilePointer(void);
extern u16 		SeekSubDirectory(s8 *fname);
extern u8 		CreateSubDirectory_(s8 *fname);
extern u8		FindItem(Find *);
extern void 	FreeFilePointer(File *file);

//________________________________________________________________________________________________________________________________________
// 
// Vaiables needed internaly for the fat16 implementation 
//				
//________________________________________________________________________________________________________________________________________

extern u8		SectorsPerCluster;
extern u32		CWD;



#endif




