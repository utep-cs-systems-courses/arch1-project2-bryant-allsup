#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
//#include "assembly.h"
    
//button1_down,button2_down,button3_down,button4_down,switch_state_changed
static int sound=1000;//control frequency of the sound
const int song1[]= {500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800,500,500,500,500,600,650,700,750,800,800,400,500,500,700,900,1100,1300,1300,1300,1300};

void state_advance()
{
  if(switch_state_changed){
    
    button1_down ? state_1():0;// raises frequency of the sound
    button2_down & sound>1800  ? state_2():0;// lowers frequency of the sound
    button3_down? state_3():0;// repeats sound
    button4_down? state_4():0;// plays a small "song"
    
    buzzer_set_period(sound);
    
    timmer();
    
    led_update();
    buzzer_set_period(0);

  }
  switch_state_changed=0;
}

void state_1()
{
  red_led=0;
  green_led=1;
  leds_changed=1;
  sound +=100;
  led_update();
}
void state_2()
{
  red_led=1;
  green_led=0;
  leds_changed=1;
  sound -=100;
  led_update();
}
void state_3()
{
  red_led=1;
  green_led=1;
  leds_changed=1;
  led_update();
}
void state_4(){
  int play = 0;
    while(play<sizeof(song1)) {
      buzzer_set_period(song1[play]);// song is played at area played
      if(play%2==0){red_led=1;} //if is a remainder of 2 red light is on
      else{red_led=0;}
      if(play%3==0){green_led=1;}//if remainder of 3 green light is on
      else{green_led=0;}
      leds_changed=1;
      led_update();
      timmer();// causes flashing
      play++;
      }
}

void timmer(){
int time = 0;
  while(time< 30000)
    {time++;}
}




