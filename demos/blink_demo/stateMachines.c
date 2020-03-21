#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  static char state  = 0;

  switch (state){
  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 0;
    break;
      }
  return 1;
  }
    
    
void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {O=0, W=1, T=2, F=3 } color = W;
  switch (color) {
  case O: changed = toggle_green();toggle_red(); color = W; break;//0 neither
  case W: changed = toggle_green(); color = T; break;//1 green
  case T: changed = toggle_red(); toggle_green(); color = F; break; //2 red
  case F: changed = toggle_green();color =O; break;//3 green and red
  }

  led_changed = changed;
  led_update();
}



