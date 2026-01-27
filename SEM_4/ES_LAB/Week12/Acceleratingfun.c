// Write a C program to rotate the stepper motor faster when SW2 is pressed

#include <LPC17xx.H> 

void clock_wise(unsigned int t); 

unsigned long int var1,var2; 
unsigned int i=0,j=0,k=0; 

unsigned int t=0, switchState = 1;

int main(void) { 
	SystemInit(); 
	SystemCoreClockUpdate(); 
	
	LPC_PINCON->PINSEL0 = 0xFFFF00FF; //P0.4 to P0.7 GPIO 
	LPC_GPIO0->FIODIR = 0x000000F0; //P0.4 to P0.7 output 
	
	LPC_PINCON->PINSEL4 &= 0xFCFFFFFF; //For Key
	LPC_GPIO2->FIODIR &= ~(1<<12);//0x00001000;
	
	while(1){ 
		switchState = (LPC_GPIO2->FIOPIN >> 12) & 1;
		if (switchState == 0)
				t++;
		else t = 0;
		
		clock_wise(t);

		for(k=0;k<1300;k++);        // Delay to show clock Rotation  

	} // End of while(1) 
} // End of main 

void clock_wise(unsigned int t) { 
	var1 = 0x00000008;         //For Clockwise 
	for(i=0;i<=3;i++)         // for A B C D Stepping 
	{ 
		var1 = var1<<1;        //For Clockwise 
		LPC_GPIO0->FIOPIN = var1; 

		for(k=0;k<3000-25*t;k++); //for step speed variation          
	} 
} 
