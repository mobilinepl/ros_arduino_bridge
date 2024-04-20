/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

#ifdef JGB37_MOTOR
  #define MOTOR_RIGHT_SPD 25
  #define MOTOR_RIGHT_DIRECTION 26
  #define MOTOR_LEFT_DIRECTION  32
  #define MOTOR_LEFT_SPD 33
#endif

void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
