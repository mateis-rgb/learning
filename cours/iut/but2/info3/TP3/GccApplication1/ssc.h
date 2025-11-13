// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// + Copyright (c) 2008 Stephan Busker
// + FOR NON COMMERCIAL USE ONLY
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+ Redistributions of source code (with or without modifications) must retain the above copyright notice, 
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

#ifndef __SSC_H
#define __SSC_H

#include "datatypes.h"


//-------------------------------------- Hardwarespecific definitions --------------------------------------

#define MMC_Write			PORTB		//Port an der die MMC/SD-Karte angeschlossen ist also des SPI 
#define MMC_Read			PINB
#define MMC_Direction_REG	DDRB	
#define MMCS_Write			PORTC		//Port an der die MMC/SD-Karte angeschlossen ist also des SPI 
#define MMCS_Read			PINC
#define MMCS_Direction_REG	DDRC


//#define	__MMC_INTERFACE_INVERTED		// the interface between the controller and the sd-card uses an inverting leveltranslator (transistorinverter)
//#define __SSC_RX_FIFO
										// and therefore the signals to or from the memorycard have to be inverted.

#define SPI_DI				6		//MISO du PORTB 
#define SPI_DO				5		//MOSI du PORTB
#define SPI_Clock			7		// SCK du PORTB
#define MMC_Chip_Select	    7		//CS_SD du PORTC
#define SPI_SS				4		//SS# non utilisé ici 


	
/*
	#define SPCR  SPCR0
	#define SPE   SPE0
	#define MSTR  MSTR0
	#define SPSR  SPSR0
	#define SPDR  SPDR
	#define SPIF  SPIF0
	#define SPR0  SPR00
	#define SPR1  SPR01
	#define SPI2X SPI2X0	
	#define CPOL  CPOL0
	*/



//________________________________________________________________________________________________________________________________________
// 
// Functions needed for accessing the sdcard.
//				
//________________________________________________________________________________________________________________________________________

extern void 			SSC_Init(void);
extern void 			SSC_Init_High(void);
extern u8 				SSC_GetChar (void);
extern void 			SSC_PutChar (u8);
extern void 			SSC_Enable(void);
extern void 			SSC_Disable(void);
extern void 			SSC_ClearRxFifo(void);



#endif
