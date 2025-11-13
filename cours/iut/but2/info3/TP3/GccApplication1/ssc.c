// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Copyright (c) 2008 Stephan Busker
// + Nur für den privaten Gebrauch
// + FOR NON COMMERCIAL USE ONLY
// + www.Mikro-control.de
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Es gilt für das gesamte Projekt (Hardware, Software, Binärfiles, Sourcecode und Dokumentation), 
// + dass eine Nutzung (auch auszugsweise) nur für den privaten (nicht-kommerziellen) Gebrauch zulässig ist. 
// + Sollten direkte oder indirekte kommerzielle Absichten verfolgt werden, ist mit mir (stephan.busker@mikro-control.de) Kontakt 
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

#include <avr/io.h>

#include "ssc.h"
#include "fat16.h"

//________________________________________________________________________________________________________________________________________
// Module name:			fat16.c 
// Compiler used:		avr-gcc 3.4.5
// Last Modifikation:	05.10.2008
// Version:				1.04
// Authors:				Stephan Busker 	
// Description:			Source files for access to the synchrnous serial channel.
//						Copyright (C) 2007 Stephan Busker
//........................................................................................................................................
// Functions:			extern void 			SSC_Init(void);		
//						extern u8				SSC_GetChar (void);
//						extern void 			SSC_PutChar (u8 Byte);
//						extern void 			SSC_Disable(void); 
//						extern void 			SSC_Enable(void); 
//........................................................................................................................................
// ext. functions:		extern u8 SDC_GetSector  (u32,u8*);		
//						extern u8 SDC_PutSector (u32,u8*);
//........................................................................................................................................
//
// URL:					www.Mikro-Control.de
// mailto:				stephan.busker@mikro-control.de
//________________________________________________________________________________________________________________________________________




//________________________________________________________________________________________________________________________________________
// Funtion: 	SSC_Init(void);
// 
// Description:	This function initialises the synchronus serial channel to the sdcard in lowspeed mode during initialization. 
//				
//
// Returnvalue: none
//________________________________________________________________________________________________________________________________________

void SSC_Init(void)
{
	MMC_Direction_REG &=~(1<<SPI_DI);								// Set the direction of the ssc-port
	MMC_Direction_REG |= (1<<SPI_Clock);							//      _______                          _______
	MMC_Direction_REG |= (1<<SPI_DO);								// CS		   \________________________/
	MMCS_Direction_REG |= (1<<MMC_Chip_Select);						// 
	MMC_Direction_REG |= (1<<SPI_SS);								//                 ___     ___     ___
																	// clk  __________/   \___/   \___/   \_________
																	//
	SSC_Disable();													//               ___             ___
																	// data_________/   \___________/   \___________

																	// initialise ssc, clock = Idel low
																	// devide clock by 64
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1); 							// Enable SSC in mastermode, invert clockpolarity (idle high)	
	#ifdef __MMC_INTERFACE_INVERTED
	SPCR = (SPCR | (1<<CPOL)); 
	#endif
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	SSC_Init_High(void);
// 
// Description:	This function initialises the synchronus serial channel to the sdcard using highspeed mode. 
//				
//
// Returnvalue: none
//________________________________________________________________________________________________________________________________________

void SSC_Init_High(void)
{
	MMC_Direction_REG &=~(1<<SPI_DI);								// Set the direction of the ssc-port
	MMC_Direction_REG |= (1<<SPI_Clock);							//      _______                          _______
	MMC_Direction_REG |= (1<<SPI_DO);								// CS		   \________________________/
	MMCS_Direction_REG |= (1<<MMC_Chip_Select);						// 
	MMC_Direction_REG |= (1<<SPI_SS);								//                 ___     ___     ___
																	// clk  __________/   \___/   \___/   \_________
																	//
	SSC_Disable();													//               ___             ___
																	// data_________/   \___________/   \___________

																	// initialise ssc, clock = Idel low
																	// devide clock by 8
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR1); 							// Enable SSC in mastermode, invert clockpolarity (idle high)	
	#ifdef __MMC_INTERFACE_INVERTED
	SPCR = (SPCR |(1<<CPOL)); 
	#endif
}




//________________________________________________________________________________________________________________________________________
// Funtion: 	void SSC_ClearRxFifo(void);
// 
// Description:	Clears the fifo of the ssc if the controller used has a builtin fifo.
//				
//
// Returnvalue: none
//________________________________________________________________________________________________________________________________________


void SSC_ClearRxFifo(void)
{
	// enter your code here to clear the rx-fifo of the ssc.										
}



//________________________________________________________________________________________________________________________________________
// Funtion: 	SSC_GetChar(void);
// 
// Description:	This function reads one byte from the SSC
//				
//
// Returnvalue: the byte received.
//________________________________________________________________________________________________________________________________________

u8 SSC_GetChar (void)
{
	u8 Byte = 0;

	#ifdef __MMC_INTERFACE_INVERTED
	SPDR = 0x00;										// read one byte of data from the SSC
	#else
	SPDR = 0xff;										// read one byte of data from the SSC	
	#endif
	
	while(!(SPSR & (1<<SPIF))){};						// wait until the data has been read.
	Byte = SPDR;

	#ifdef __MMC_INTERFACE_INVERTED
	return (~Byte);				
	#else
	return (Byte);										// the byte received 
	#endif
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	SSC_PutChar(u8 Byte);
// 
// Description:	This function writes one byte to the SSC 
//				
//
// Returnvalue: none
//________________________________________________________________________________________________________________________________________

void SSC_PutChar (u8 Byte)
{
	#ifdef __MMC_INTERFACE_INVERTED
	SPDR = ~Byte; 										// send one byte of data to the SSC
	#else
	SPDR =  Byte; 										// send one byte of data to the SSC
	#endif
	while(!(SPSR & (1<<SPIF))) 						// wait until data was send.
	{
	}
}


//________________________________________________________________________________________________________________________________________
// Funtion: 	SSC_Disable(void);
// 
// Description:	This function enables chipselect of the sdcard (active low) 
//				
//
// Returnvalue: none
//________________________________________________________________________________________________________________________________________

void SSC_Disable(void) 
{ 
	#ifdef __MMC_INTERFACE_INVERTED
	MMCS_Write &= ~(1<<MMC_Chip_Select);					// disable chipselect of the sdcard (active low). 
	#else
	MMCS_Write |= (1<<MMC_Chip_Select); 					// enable chipselect of the sdcard (active low). 
	#endif
}




//________________________________________________________________________________________________________________________________________
// Funtion: 	SSC_Enable(void);
// 
// Description:	This function disables chipselect of the sdcard (active low) 
//				
//
// Returnvalue: none
//________________________________________________________________________________________________________________________________________

void SSC_Enable(void) 
{ 
	#ifdef __MMC_INTERFACE_INVERTED
	MMCS_Write |= (1<<MMC_Chip_Select); 					// enable chipselect of the sdcard (active low). 
	#else
	MMCS_Write &= ~(1<<MMC_Chip_Select);					// disable chipselect of the sdcard (active low). 
	#endif
}

