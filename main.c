/************************************
 * #pragma directives...
************************************/
#pragma config FEXTOSC = HS
#pragma config RSTOSC = EXTOSC_4PLL 
#pragma config WDTE = OFF        

/************************************
 * #include directives...
 ************************************/
#include <xc.h>

/************************************
 * #define directives...
 ************************************/
#define _XTAL_FREQ 64000000 

/************************************
/ main function
 * ...
************************************/
void main(void) {    
    // setup pin for output (connected to LED)
    LATDbits.LATD7=0;   //set initial output state
    TRISDbits.TRISD7=0; //set TRIS value for pin (output)
    
    LATHbits.LATH3=0; //set initial output state
    TRISHbits.TRISH3=0; //set TRIS value for pin (output)
    
    // setup pin for input (connected to button)
    TRISFbits.TRISF2=1; //set TRIS value for pin (input)
    ANSELFbits.ANSELF2=0; //turn off analogue input on pin
    
    TRISFbits.TRISF3=1; //set TRIS value for pin (input)
    ANSELFbits.ANSELF3=0; //turn off analogue input on pin
    
    while (1) { //infinite while loop - repeat forever
        
        while (PORTFbits.RF2 && PORTFbits.RF3); //empty while loop (wait for either button to be pressed)
        
        if (!PORTFbits.RF2) { //if button 1 is pressed
            
            LATDbits.LATD7 = !LATDbits.LATD7; //toggle LED 1
        }
        
        if (!PORTFbits.RF3) { //if button 2 is pressed
            
            LATHbits.LATH3 = !LATHbits.LATH3; //toggle LED 2 
        }
        
        __delay_ms(200); // call built in delay function
    }
}