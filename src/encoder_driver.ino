/* *************************************************************
   Encoder definitions
   
   Add an "#ifdef" block to this file to include support for
   a particular encoder board or library. Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   ************************************************************ */
   
#ifdef USE_BASE
#include <Arduino.h>
#include "commands.h"
#include "encoder_driver.h"

#ifdef JGB37_ENCODER

volatile long right_enc_pos = 0L;
volatile long left_enc_pos = 0L;
volatile byte right_enc_state;

void initEncoder()
{
  pinMode(JGB37_ENC_RIGHT, INPUT_PULLUP);
  pinMode(JGB37_ENC_LEFT, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(JGB37_ENC_RIGHT), encRightISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(JGB37_ENC_LEFT), encLeftISR, CHANGE);
}

void encRightISR()
{
  if (digitalRead(JGB37_ENC_RIGHT) == LOW)
    right_enc_pos++;
}

void encLeftISR()
{
  if (digitalRead(JGB37_ENC_LEFT) == LOW)
    left_enc_pos++;
}

long readEncoder(int i)
{
  if (i == LEFT)
    return left_enc_pos;
  else
    return right_enc_pos;
}

void resetEncoder(int i)
{
  if (i == LEFT)
  {
    left_enc_pos = 0L;
    return;
  }
  else
  {
    right_enc_pos = 0L;
    return;
  }
}

#else
  #error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif

