#include <LPC17xx.h>

// Array for mapping digits 0-9 to their 7-segment display encoding
unsigned char tohex[10] = {0x3F, 0X06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

// Variables used for controlling the countdown and loop indices
unsigned int i = 0, j = 0;

// Array to store the digits for each of the four 7-segment display positions
long int arr[4] = {9, 9, 9, 9}; // Starts at 9999, representing a four-digit countdown

int main(){
    // Initialize the system and update the system core clock (usually required for LPC17xx setup)
    SystemInit();
    SystemCoreClockUpdate();
    
    // Configure GPIO pins for the 7-segment displays
    // LPC_GPIO0 pins 0 to 7 are set as outputs to control the 7-segment display (8 bits)
    LPC_GPIO0->FIODIR |= 0xFF0;  // Set bits 4 to 11 as output (8 bits for 7-segment display)
    
    // LPC_GPIO1 pins 23 to 26 are set as outputs to select which 7-segment digit to control
    LPC_GPIO1->FIODIR |= 0xF << 23; // Set bits 23-26 as output (4 bits for digit select)

    // Start the countdown (from 9999 to 0000)
    for(arr[3] = 9; ; arr[3]--){
        // Countdown each digit in arr[] starting from the most significant one (arr[3])
        for(arr[2] = 9; arr[2] >= 0; arr[2]--)
					for(arr[1] = 9; arr[1] >= 0; arr[1]--)
            for(arr[0] = 9; arr[0] >= 0; arr[0]--){
                // Loop through each of the four digits (arr[0] to arr[3]) and update the display
                for(i = 0; i < 4; i++){
                    // Select which digit to activate (which 7-segment display to update)
                    LPC_GPIO1->FIOPIN = i << 23; // Shift the value to activate a specific digit (0-3)

                    // Send the corresponding 7-segment encoding for each digit
                    LPC_GPIO0->FIOPIN = tohex[arr[i]] << 4; // Set the correct segment pattern for the digit
                    for(j = 0; j < 1000; j++); // Delay loop for display persistence
                }

                // Introduce additional delay between updates for visual stability
                //for(j = 0; j < 100000; j++);

                // Clear all segments before next update
                //LPC_GPIO0->FIOCLR |= 0xFF0; // Reset GPIO pins to turn off the segments
            }
        // Reset the last digit when it reaches 0 and continue the countdown
        if(arr[3] == 0)
            arr[3] = 10; // Reset the most significant digit to 10 (this makes it stop at 0000 and restart at 9999)
    }
}
