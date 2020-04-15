#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "libTimer.h"
//#include "assembly.s"
    
static int sound=1000;//control frequency of the sound
static enum{off=0,dim=1,On=2} brightness;
static char counter =0;
static char state = 3;

void state_advance()
{
  if(switch_state_changed){
    
    button1_down ? switch_1():0;// raises frequency of the sound
    button2_down ? switch_2():0;// lowers frequency of the sound
    button3_down? switch_3():0;// repeats sound
    button4_down? switch_4():0;// resets to default
    buzzer_set_period(sound);    
    timmer(5);
    led_update();
    buzzer_set_period(0);

  }
  switch_state_changed=0;
}

void switch_1()
{
    sound +=100;
    if(sound == 1800){      
      state = 5;
      sound = 1800;}
    if(sound > 1000 && sound < 1800 )
      {state = 4;}
    if (sound==1000)
      {state = 3;}
  enableWDTInterrupts();
}
void switch_2()
{
  if(sound > 500)
    {sound -= 100;}
  if(sound == 500)
    {state = 1;}
  if(sound < 1000 && sound > 500)
    {state = 2;}
  if (sound==1000)
    {state = 3;}
  enableWDTInterrupts();
}
void switch_3()
{
  enableWDTInterrupts();
}
void switch_4(){
  sound = 1000;
  state = 3;
  enableWDTInterrupts();
}

 void next() 
 {
   char temp = 0; 
   leds_changed = 1;
   count();
   switch(state) 
     { 
     case 1: 
       red_led = 0; 
       green_led = 1; 
       break; 
     case 2: 
       red_led = 0; 
       green_led = (counter<1); 
       break; 
     case 3: 
       red_led = 1; 
       green_led = 1; 
       break; 
     case 4: 
       red_led = (counter<1); 
       green_led = 0; 
       break; 
     case 5: 
       red_led = 1; 
       green_led = 0; 
       break; 
     } 
   led_update(); 
   } 

void timmer(int i){
int time = 0;
 for (int cycle =0; cycle < i; cycle++)
   {while(time< 30000) {time++;}}
}

void bright()
{brightness = (brightness + 1)%3;}

void count()
{counter = (counter + 1)%3;}




