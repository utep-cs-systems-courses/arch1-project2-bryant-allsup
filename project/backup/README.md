#Toy StartUp
*1 Make sure to make timerlib first 
-2 run make
-3 plug in given msp430 launchpad with boosterkit attached
-4 while in the toy directory make load
-5 msp430 should be running in order to check tap a button on the boosterkit

#Toy Desciption
     Toy will do different thing depending on the buttons of the boosterkit
     	 -Button 1 lowers the frequency(by 100)
	 -Button 1 will run the green led
	 -Button 2 raises the frequeny(by 100)
	 -Button 2 will run red led
   	 -Button 3 will repeat the same sound
	 -Button 3 will run bothe leds
	 -Button 4 will play a custom "song"
	 -Button 4 will dim flash both leds making it look dimmer

#Toy Bugs
     -interrupt does not work during the song
     -leds would not run right away(might be a one off thing)
