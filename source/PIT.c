
#include "MK64F12.h"
#include "PIT.h"

static uint8 PIT0_Flag = FALSE;

void PIT0_IRQHandler(){
	uint8 dummyRead;

	PIT->CHANNEL[0].TFLG |= (PIT_TFLG_TIF_MASK);
	PIT->CHANNEL[0].TCTRL &= 0x0;
	dummyRead = PIT->CHANNEL[0].TCTRL;
	PIT0_Flag = TRUE;
}

void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float period){
	ufloat32 LDVAL_trigger;
	LDVAL_trigger =(period/(1/(systemClock/2)))-1;

	PIT->MCR = 0x00;
	PIT->CHANNEL[pitTimer].LDVAL = LDVAL_trigger;
	PIT->CHANNEL[pitTimer].TCTRL |= PIT_TCTRL_TEN_MASK;
	PIT->CHANNEL[pitTimer].TCTRL |= PIT_TCTRL_TIE_MASK;
}

void PIT_clockGating(void){
	SIM->SCGC6 |= PIT_CLOCK_GATING;
}

uint8 PIT_interruptFlagStatus(void){

}

uint8 PIT_getIntrStutus(void){
	return PIT0_Flag;
}

void PIT_clear(PIT_Timer_t pitTimer){
	PIT0_Flag = FALSE;
}
