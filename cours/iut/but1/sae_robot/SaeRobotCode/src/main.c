#include <Arduino.h>

#define SPEED 0x80

const int PWMG = 10;
const int SENSG = 8;

const int PWMD = 9;
const int SENSD = 7;

void move (int speed, int LeftDirection, int RightDirection);

void stop (void);

void moveBackward (void);

void moveForward (void);

void moveRight (void);

void moveLeft (void);

void setup (void) {
  pinMode(PWMG, OUTPUT);
  pinMode(PWMD, OUTPUT);
  pinMode(SENSG, OUTPUT);
  pinMode(SENSD, OUTPUT);
}

void loop (void) {
  moveForward();
  delay(1000);
  stop();
  delay(1000);
  moveBackward();
  delay(1000);
  stop();
  delay(1000);
  moveLeft();
  delay(1000);
  stop();
  delay(1000);
  moveRight();
  delay(1000);
  stop();
  delay(1000);
}


void move (int speed, int LeftDirection, int RightDirection)
{
  analogWrite(PWMG, speed);
  analogWrite(PWMD, speed);

  if (speed != 0)
  {
    digitalWrite(SENSG, LeftDirection);
    digitalWrite(SENSD, RightDirection);
  }
}


void stop (void)
{
  move(0, LOW, LOW);
}


void moveBackward (void)
{
  move(SPEED, LOW, HIGH);
}


void moveForward (void)
{
  move(SPEED, HIGH, LOW);
}


void moveRight (void)
{
  move(SPEED, HIGH, HIGH);
}


void moveLeft (void)
{
  move(SPEED, LOW, LOW);
}
