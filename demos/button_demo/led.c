#include <msp430.h>
#include "led.h"
#include "switches.h"

static int state=0;// keeps track of lights

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update(){

   if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */

    
    // (:) seperates the LEDs  (left green, right red)
    // when switch is pressed  green is on else red is off

    
    //switch_state_down
    state = state ? 0:1;
    ledFlags |= state ? LED_GREEN : LED_RED;//LED_GREEN ON

      
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
    }
 switch_state_changed = 0;
}

