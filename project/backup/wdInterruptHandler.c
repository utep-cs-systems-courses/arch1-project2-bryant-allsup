#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char time_count = 0;
  if (++time_count == 125)
    {
    time_count = 0;
  }
}
