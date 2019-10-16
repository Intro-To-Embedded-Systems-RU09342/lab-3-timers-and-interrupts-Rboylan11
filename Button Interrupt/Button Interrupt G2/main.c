//Ryan Boylan
//G2
//Button Interrupt
//Lab 3.1

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 //stop watchdog timer

  P1DIR |= BIT0;                            //set direction to output
  P1IE  |= BIT3;                            //enable interrupt
  P1IES |= BIT3;                            //Hi/lo edge trigger
  P1REN |= BIT3;                            //enable pull up resistor
  P1IFG &= ~BIT3;                           //clear interrupt flag
  __bis_SR_register(LPM4_bits + GIE);       //low power mode and enable interrupt
}

#pragma vector=PORT1_VECTOR                 //interrupt protocol and memory allocation
__interrupt void Port_1(void)               //interrupt name
{
  P1OUT ^= BIT0;                            //toggle LED
  P1IFG &= ~BIT3;                           //clear interrupt flag
}
