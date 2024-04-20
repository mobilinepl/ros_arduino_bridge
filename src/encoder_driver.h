/* *************************************************************
   Encoder driver function definitions - by James Nugen
   ************************************************************ */
   
#ifdef JGB37_ENCODER
  #define JGB37_ENC_RIGHT 18
  #define JGB37_ENC_LEFT 19
  void encLeftISR();
  void encRightISR();
  void initEncoder();
#endif
   
long readEncoder(int i);
void resetEncoder(int i);
void resetEncoders();

