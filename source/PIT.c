/*
 * PIT.c
 *
 * Created on: 18/09/17
 * Author: Daniel Barragán and Alejandro Ávila
 *
 */


#include "MK64F12.h"
#include "PIT.h"
#include "DataTypeDefinitions.h"

void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float perior){

}

void PIT_clockGating(void){
	SIM->SCGC6 |= PIT_CLOCK_GATING; /** Bit 9 of SIM_SCGC5 is  set*/
	// turn on PIT
	PIT_MCR = 0X0;
	//Timer 1
	PIT_LDVAL_TSV(0x0003E7FF);
	PIT_TCTRL1 = TIE;
	PIT_TCTRL1 |= TEN;
}

uint8 PIT_interruptFlagStatus(void){
	//Omitir
}

uint8 PIT_getIntrStutus(void){
	return 	PIT;
}

void PIT_clear(void){
	PIT_TFLG0 |= PIT_TFLG_TIF_MASK;
	PIT_TCTRL0;
	PIT_TCTRL_0 &= ~(PIT_TFLG_TIF_MASK);
	PIT_TCTRL_0 &= ~(PIT_TFLG_TEN_MASK);
}

