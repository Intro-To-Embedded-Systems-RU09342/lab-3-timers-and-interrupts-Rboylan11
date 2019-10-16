# Button Interrupt
The objective of this lab is to make an LED blink with the press of a button, but without constantly checking if the button is pressed. This is done by an interrupt. The code simply turns on an LED, then when the button is pressed, an interrupt is called which toggles the state of the LED. Now it is not constantly checking for a button click and the desired output is still obtained.

The difference in code between the two boards is that there are different pins for the LEDs and buttons. Also, for the FR6989 you must disable the GPIO power-on default high-impedance mode. 