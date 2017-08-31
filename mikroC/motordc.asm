
_SetPWM1:

	MOVF       FARG_SetPWM1_DutyCycle+0, 0
	MOVWF      R0+0
	MOVF       FARG_SetPWM1_DutyCycle+1, 0
	MOVWF      R0+1
	RRF        R0+1, 1
	RRF        R0+0, 1
	BCF        R0+1, 7
	RRF        R0+1, 1
	RRF        R0+0, 1
	BCF        R0+1, 7
	MOVF       R0+0, 0
	MOVWF      CCPR1L+0
	MOVLW      207
	ANDWF      CCP1CON+0, 1
L_end_SetPWM1:
	RETURN
; end of _SetPWM1

_initPWM:

	BCF        TRISC1_bit+0, BitPos(TRISC1_bit+0)
	BCF        TRISC2_bit+0, BitPos(TRISC2_bit+0)
	MOVLW      255
	MOVWF      PR2+0
	MOVLW      6
	MOVWF      T2CON+0
	CLRF       CCPR1L+0
	MOVLW      12
	MOVWF      CCP1CON+0
	CLRF       CCPR2L+0
	MOVLW      12
	MOVWF      CCP2CON+0
L_end_initPWM:
	RETURN
; end of _initPWM

_main:

	CALL       _initPWM+0
	MOVLW      210
	MOVWF      CCPR1L+0
	MOVLW      10
	MOVWF      CCPR2L+0
L_end_main:
	GOTO       $+0
; end of _main
