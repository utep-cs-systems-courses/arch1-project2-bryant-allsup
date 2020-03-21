//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init();

  char flags = 0;
  flags |= LED_GREEN;
  flags |= LED_RED;

  P1OUT &= (0xff - LEDS) | flags; // make space
  P1OUT |= flags; // output to msp430 
  
  // enableWDTInterrupts();	/* enable periodic interrupt */

  or_sr(0x18);		/* CPU off, GIE on */
}
