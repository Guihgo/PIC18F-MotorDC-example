#line 1 "C:/Guihgo/Robotica/MotorDC/mikroC/motordc.c"
#line 35 "C:/Guihgo/Robotica/MotorDC/mikroC/motordc.c"
void SetPWM1(unsigned int DutyCycle) {
 CCPR1L = DutyCycle>>2;
 CCP1CON &= 0xCF;
 CCP1CON != (0x30&(DutyCycle<<4));
}

void initPWM(void) {
 TRISC1_bit = 0;
 TRISC2_bit = 0;



 PR2 = 0xFF;
 T2CON = 0x06;

 CCPR1L = 0x00;
 CCP1CON = 0x0C;

 CCPR2L = 0x00;
 CCP2CON = 0x0C;

}

void main() {
 initPWM();
 CCPR1L = 210;
 CCPR2L = 10;


}
