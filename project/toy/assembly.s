.arch msp430g2553

      .text
      .global timmer:
timmer:
	mov #0,r12
	begin
	cmp #3000, r12
	JL end
	add #1,r12
	JMP begin
	end
	ret
