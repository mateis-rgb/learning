//-----------------------------------------------------------------------------
// Copyright 2023 Peter Balch
//   displays an ECG and PPG
//   computes QT interval
//   computes PAT
//   Arduino Nano
//   Angers sequence readout potentiometer dynamic line
//-----------------------------------------------------------------------------

#include <Arduino.h>
#include <SPI.h>
#include "SimpleILI9341.h"


// get register bit - faster: doesn't turn it into 0/1
#ifndef getBit
#define getBit(sfr, bit) (_SFR_BYTE(sfr) & _BV(bit))
#endif
#define sqr(x) ((x)*(x))

//-----------------------------------------------------------------------------
// Global Constants and Typedefs
//-----------------------------------------------------------------------------

const int TFT_WIDTH = 320;
const int TFT_HEIGHT = 240;

// pins
const int ECG_IN = A2;
const int BUTTON_IN = A5;
const int LO_P_IN = A0;
const int LO_N_IN = A1;

// Display pins
const int TFT_CS    = 10;
const int TFT_CD    = 8;
const int TFT_RST   = 9;

const int sps = 200; // Samples per Sec
const int SamplePeriod = 1000 / sps; // mSec
const int PoincareScale = 10;
const int PoincareLeft = 40;
const int PoincareBottom = TFT_HEIGHT - 12;
const int nDiff = sps / 65; /* differentiate = aa[i]-aa[i-nDiff]*/

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------

int i=0;
int j=0;
int val=0; //analog value
int val_alt=0; // old value
float val_rad=0;  // angle in radians
float val_rad_alt=0; // old angle in radians
float angle = 2*3.1415/1023;  // umrechnung in Bogenmaß
float pi_quarter = 0.7854;  // Pi Viertel
long int val_display;  //
int arrow_x_start=160; //start position x
int arrow_x_end=260; //ende position x
int arrow_y_start=120; //max position x
int arrow_y_end=120; //ende position y
// we calculate endeposition = cos(val/(2*pi)), sin(val/(2*pi)

//-------------------------------------------------------------------------
// setup
//-------------------------------------------------------------------------
void setup(void)
{
  pinMode(ECG_IN, INPUT);
  analogReference(EXTERNAL);

  ILI9341Begin(TFT_CS, TFT_CD, TFT_RST, TFT_WIDTH, TFT_HEIGHT, ILI9341_Rotation3);
  ILI9341fast = true;

  int16_t i;
  ClearDisplay(TFT_BLACK);
  for (i = 0; i < TFT_HEIGHT; i++)
    if (i % 8 == 0)
      DrawHLine(0, i, TFT_WIDTH, TFT_MAROON);
  for (i = 0; i < TFT_WIDTH; i++)
    if (i * 25 % (1000 / SamplePeriod) == 0)
      DrawVLine(i, 0, TFT_HEIGHT, TFT_MAROON);

  for (i = 0; i < TFT_HEIGHT; i++)
    if (i % 40 == 0)
      DrawHLine(0, i, TFT_WIDTH, TFT_RED);
  for (i = 0; i < TFT_WIDTH; i++)
    if (i * 5 % (1000 / SamplePeriod) == 0)
      DrawVLine(i, 0, TFT_HEIGHT, TFT_RED);

}


//-----------------------------------------------------------------------------
// Main loop
//-----------------------------------------------------------------------------
void loop(void)
{
  val=analogRead(ECG_IN);
  if (val_alt != val){
  val_rad=val;
  val_rad=val_rad*angle;
  // erase the old line
  DrawLine(???, ???, ???, ???, TFT_BLACK);  // the line itself
  DrawLine(???, ???, ???, ???, TFT_BLACK);  // the arrow line one side
  DrawLine(???, ???, ???, ???, TFT_BLACK);  // the arrow line one side
  // draw new line
  DrawLine(160, 120, 160+100*cos(val_rad), 120+100*sin(val_rad), TFT_WHITE);  // the line itself
  DrawLine(160+100*cos(val_rad), 120+100*sin(val_rad), 160+100*cos(val_rad)-10*cos(val_rad+pi_quarter), 120+100*sin(val_rad)-10*sin(val_rad+pi_quarter), TFT_WHITE);  // the arrow line one side
  DrawLine(160+100*cos(val_rad), 120+100*sin(val_rad), 160+100*cos(val_rad)-10*cos(val_rad-pi_quarter), 120+100*sin(val_rad)-10*sin(val_rad-pi_quarter), TFT_WHITE);  // the arrow line one side
  val_rad_alt=val_rad;
  val_alt=val;
  }
  delay(50);
}
