//Ryan Boylan
//6989
//Button Interrupt
//Lab 3.1

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 //stop watchdog timer

  P1DIR |= BIT0;                            //set direction to output
  P1IE  |= BIT1;                            //enable interrupt
  P1IES |= BIT1;                            //Hi/Lo edge enabled
  P1REN |= BIT1;                            //enable pull up resistor
  P1IFG &= ~BIT1;                           //clear interrupt flag

  PM5CTL0 &= ~LOCKLPM5;                     // Disable the GPIO power-on default high-impedance mode

  __bis_SR_register(LPM4_bits + GIE);       //enable low power mode and interrupts
}

#pragma vector=PORT1_VECTOR                 //interrupt protocol and memory allocatio
__interrupt void Port_1(void)               //interrupt name
{
  P1OUT ^= BIT0;                            // P1.0 = toggle
  P1IFG &= ~BIT1;                           // P1.3 IFG cleared
}
