	.arch msp430g2553

	.data
state:		 .word 1


	.text
jt:	.word default
	.word case1
	.word case2
	.word case3
	.word case4
	.word case5

	
	.global next
next:	mov.b #1,leds_changed
	cmp #6, state
	jhs end
	
	mov &state,r12
	add r12,r12
	mov jt(r12), r0

case1:	mov #1,green_led
	mov #0,red_led
	jmp end
	
case2:	mov #1,green_led
	mov #0,red_led
	jmp end
	
case3:	mov #1,green_led
	mov #1,red_led
	jmp end
	
case4:	mov #0,green_led
	mov #1,red_led
	jmp end
	
case5:	mov #0,green_led
	mov #1,red_led
	jmp end
	
default:mov #0,green_led
	mov #0,red_led
	jmp end

end:	call led_update
	pop r0
