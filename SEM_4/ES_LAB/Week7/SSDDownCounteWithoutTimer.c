#include <LPC17xx.h>

// Array for mapping digits 0-9 to their 7-segment display encoding
unsigned char tohex[10] = {0x3F, 0X06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

// Variables used for controlling the countdown and loop indices
unsigned int i = 0, j = 0, temp, counter=9999;

int main(){
    // Initialize the system and update the system core clock (usually required for LPC17xx setup)
    SystemInit();
    SystemCoreClockUpdate();
	
    // Configure GPIO pins for the 7-segment displays
    // LPC_GPIO0 pins 0 to 7 are set as outputs to control the 7-segment display (8 bits)
    LPC_GPIO0->FIODIR |= 0xFF0;  // Set bits 4 to 11 as output (8 bits for 7-segment display)
    
    // LPC_GPIO1 pins 23 to 26 are set as outputs to select which 7-segment digit to control
    LPC_GPIO1->FIODIR |= 0xF << 23; // Set bits 23-26 as output (4 bits for digit select) - Not sure why yet, mux => 23 and 24th bit only

		while (1){
			temp = counter;
			for(i=0; i<4; i++){			
				LPC_GPIO1->FIOPIN =	i << 23;
				LPC_GPIO0->FIOPIN = tohex[temp%10] << 4;
				for(i=0; i<1000; i++);
				temp /= 10;			
			}

			counter--;
			if (counter == 0)
				counter = 9999;

		} 
}
