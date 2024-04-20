/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE
#include <Arduino.h>
#include "commands.h"
#include "motor_driver.h"

#ifdef JGB37_MOTOR
  
void initMotorController() {
  pinMode(MOTOR_LEFT_SPD, OUTPUT);
  pinMode(MOTOR_RIGHT_SPD, OUTPUT);    
  pinMode(MOTOR_LEFT_DIRECTION, OUTPUT);
  pinMode(MOTOR_RIGHT_DIRECTION, OUTPUT);
  
  analogWrite(MOTOR_LEFT_SPD, 0);
  analogWrite(MOTOR_RIGHT_SPD, 0);
  digitalWrite(MOTOR_LEFT_DIRECTION, 0);
  digitalWrite(MOTOR_RIGHT_DIRECTION, 1);
}

void setMotorSpeed(int i, int spd)
{
  unsigned char reverse = 0;

  if (spd < 0)
  {
    spd = -spd;
    reverse = 1;
  }
  if (spd > 255)
  {
    spd = 255;
  }

  if (i == LEFT)
  {
    if (reverse == 0) {
      digitalWrite(MOTOR_LEFT_DIRECTION, HIGH);
    } else {
      digitalWrite(MOTOR_LEFT_DIRECTION, LOW);
    }
    analogWrite(MOTOR_LEFT_SPD, spd);
  }
  else /*if (i == RIGHT) //no need for condition*/
  {
    if (reverse == 0) {
      digitalWrite(MOTOR_RIGHT_DIRECTION, LOW);
    } else {
      digitalWrite(MOTOR_RIGHT_DIRECTION, HIGH);
    }
    analogWrite(MOTOR_RIGHT_SPD, spd);
  }
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
  setMotorSpeed(LEFT, leftSpeed);
  setMotorSpeed(RIGHT, rightSpeed);
}

#else
  #error A motor driver must be selected!
#endif

#endif
