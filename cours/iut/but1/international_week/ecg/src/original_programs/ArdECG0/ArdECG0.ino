//-----------------------------------------------------------------------------
// Copyright 2021 Peter Balch
// ADC tester
//   reads ADC 
//   sends value to PC
//-----------------------------------------------------------------------------

#include <Arduino.h>
#include <SPI.h>

//-----------------------------------------------------------------------------
// Defines, constants and Typedefs
//-----------------------------------------------------------------------------

// pins
const int ECG_IN = A0;
const int FAKE_OUT = 3;

// get register bit - faster: doesn't turn it into 0/1
#ifndef getBit
#define getBit(sfr, bit) (_SFR_BYTE(sfr) & _BV(bit))
#endif

//-----------------------------------------------------------------------------
// Global Constants
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// testADCsimple
//-----------------------------------------------------------------------------
void testADCsimple(void)
{
  int i = analogRead(ECG_IN);
  Serial.println(i);
}

//-------------------------------------------------------------------------
// setup
//-------------------------------------------------------------------------
void setup(void)
{
  Serial.begin(57600);
  Serial.println("testADC");

  pinMode(ECG_IN, INPUT);
  analogReference(EXTERNAL);
  analogRead(ECG_IN); // initialise ADC to read audio input

//  pinMode(2, OUTPUT);
  pinMode(FAKE_OUT, OUTPUT);
//  digitalWrite(2,HIGH);

  Serial.println("0 0 1024");
}

//-----------------------------------------------------------------------------
// Main routines
// loop
//-----------------------------------------------------------------------------
void loop(void)
{
  static unsigned long nextTime = 0;
  static uint16_t i = 0;
  
  if (millis() > nextTime) {
    nextTime = nextTime + 5;
    testADCsimple();

    i++;
    digitalWrite(FAKE_OUT,(i % 200) < 10);
//    digitalWrite(FAKE_OUT,(i % 10) < 5);
  }
}
