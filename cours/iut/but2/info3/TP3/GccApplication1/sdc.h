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

#ifndef _SDC_H
#define _SDC_H

#include "datatypes.h"


#define SDC_DEBUG
#define CARD_DETECT (!(PIND & 0x04))




//________________________________________________________________________________________________________________________________________
// 
// Functions needed for accessing the sdcard.
//				
//________________________________________________________________________________________________________________________________________

typedef enum
{
  SD_SUCCESS = 0,
  SD_ERROR_NOCARD,
  SD_ERROR_RESET,
  SD_ERROR_INITIALIZE,
  SD_ERROR_BAD_RESPONSE,
  SD_ERROR_BAD_VOLTAGE_RANGE,
  SD_ERROR_NO_SDCARD,
  SD_ERROR_TIMEOUT,
  SD_ERROR_CRC_DATA,
  SD_ERROR_WRITE_DATA,
  SD_ERROR_READ_DATA,
  SD_ERROR_SET_BLOCKLEN,
  SD_ERROR_UNKNOWN
} SD_Result_t;


extern SD_Result_t	SDC_Init(void);
extern SD_Result_t 	SDC_GetSector (u32 ,u8 *);
extern SD_Result_t 	SDC_PutSector (u32, const u8 *);
extern SD_Result_t	SDC_Deinit(void);

#endif // _SDC_H


