#include <LPC17xx.h>
//Declaration outside everything


unsigned int counter = 0, i;

int main(void){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	
	while(1){
		LPC_GPIO0->FIOCLR = 0x00000FF0;
		LPC_GPIO0->FIOSET = (counter<<4);
		for (i=0; i<100000; i++); //delay
		counter++;
		if (counter>0xFF) 
			break;
	}
}
