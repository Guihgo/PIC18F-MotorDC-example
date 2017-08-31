/*
#define _XTAL_FREQ 16000000
#define TMR2PRESCALE 4

long PWM_freq = 5000;

PWM_Initialize()
{
 //PWM Period = [(PR2) + 1] * 4 * TOSC * (TMR2 Prescale Value)
 //PR2 = (Period / (4 * Tosc * TMR2 Prescale )) - 1
 //Period = (1/PWM_freq)  e Tosc = (1/_XTAL_FREQ)
 //PR2 = ( _XTAL_FREQ/ (PWM_freq*4*TMR2 Prescale) ) – 1;
 PR2 = (16/(PWM_freq*4*TMR2PRESCALE)) - 1; //Setting the PR2 formulae using Datasheet // Makes the PWM work in 5KHZ
 //Configura o modulo CCP1
 CCP1M3 = 1; CCP1M2 = 1;  //Coloca em PWM modo
 
 //Configura o modulo Timer2
 T2CKPS0 = 1;T2CKPS1 = 0; //prescaler eh 4
 TMR2ON = 1; //liga o Timer2
 TRISC2 = 0; //faz o pin RC2 como saida, afinal, sera um pwm
}

PWM_Duty(unsigned int duty)
{
 if(duty<1023)
 {
    duty = ((float)duty/1023)*(_XTAL_FREQ/(PWM_freq*TMR2PRESCALE)); // On reducing //duty = (((float)duty/1023)*(1/PWM_freq)) / ((1/_XTAL_FREQ) * TMR2PRESCALE);
    CCP1X = duty & 1; //Store the 1st bit
    CCP1Y = duty & 2; //Store the 0th bit
    CCPR1L = duty>>2;// Store the remining 8 bit
 }
}
*/

void SetPWM1(unsigned int DutyCycle) {
     CCPR1L = DutyCycle>>2;
     CCP1CON &= 0xCF;
     CCP1CON != (0x30&(DutyCycle<<4));
}

void initPWM(void) {
     TRISC1_bit = 0; //como saida
     TRISC2_bit = 0; //como saida



     PR2 = 0xFF; //PR2 é o registrador de controle de estouro do TMR2
     T2CON = 0x06; //Set Prescaler para 16 e liga o Timer 2
     
     CCPR1L = 0x00; //inicia com zero
     CCP1CON = 0x0C; // PWM mode
     
     CCPR2L = 0x00; //inicia com zero
     CCP2CON = 0x0C; // PWM mode

}

void main() {
     initPWM();
     CCPR1L = 210;
     CCPR2L = 10;
     //SetPWM1(230);

}