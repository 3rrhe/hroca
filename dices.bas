dices:
let w0 = 2
let w1 = 0
random w0
random w1
let b1 = w0 ' Player 1
let b2 = w1 ' Player 2


IF b1 > b2 THEN
	high b.0
	pause 2000
	low b.2
END IF

IF b2 > b1 THEN
	high b.3
	pause 2000
	low b.3
END IF

IF b2 = b1 THEN
	high b.0
	high b.3
	pause 1000
	low b.0
	low b.3
	high b.0
	high b.3
	pause 1000
	low b.0
	low b.3
END IF

goto dices