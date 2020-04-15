#Toy StartUp
*1 Make sure to make timerlib first 
-2 run make
-3 plug in given msp430 launchpad with boosterkit attached
-4 while in the toy directory make load
-5 msp430 should be running in order to check tap a button on the boosterkit

#Toy Desciption
     Toy will do different thing depending on the buttons of the boosterkit
     	 -Button 1 lowers the frequency(by 100)
	 -Button 1 will eventually turn the lights a dim red and then a full red
	 -Button 2 raises the frequeny(by 100)
	 -Button 2 will eventullt turn the lights green led
   	 -Button 3 will repeat the same sound
	 -button 3 will keep
	 -Button 4 will reset to default
	 -Button 4 will turn on both leds

#Toy Bug
     -Dim lights will go completley on and will not go back to dim until
     	  -you go the opposite direction twice and then intitial direction
	  once
	  -you go to both lights on
     -make with assembly does gives errors because of "#"
     -commenting out the "next()" causes the program to not recognize variable
     "sound"
	-"Sound" is never used in "next()"
