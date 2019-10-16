//Ryan Boylan
//6989
//Timer A Blink
//Lab 3.2

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 //stop watchdog timer

  P1DIR |= BIT0;                            //set direction to output
  P1OUT |= ~BIT0;                           //turn pin on

  P9DIR |= BIT7;                            //set direction to output
  P9OUT |= ~BIT7;                           //turn pin on

  PM5CTL0 &= ~LOCKLPM5;                     // Disable the GPIO power-on default high-impedance mode

  TA0CCTL0 = CCIE;                          //enable timer interrupt for compare mode
  TA0CTL = TASSEL_2 + MC_1 + ID_3;          //smclk, timer in up mode, divide clock by 8
  TA0CCR0 = 50000;                          //clk = 10^6 Hz / (8*TA0CCR0)

  TA1CCTL0 = CCIE;                          //enable timer interrupt for compare mode
  TA1CTL = TASSEL_2 + MC_1 + ID_3;          //smclk, timer in up mode, divide clock by 8
  TA1CCR0 = 25000;                          //clk = 10^6 Hz / (8*TA0CCR0)

  __enable_interrupt();                     //enable interrupt
  __bis_SR_register(LPM0 + GIE);            //enable low power mode and interrupts
}
#pragma vector=TIMER0_A0_VECTOR             //interrupt protocol and memory allocation
__interrupt void TIMER_A0(void)             //interrupt name
{
  P1OUT ^= BIT0;                            //toggle LED
}
#pragma vector=TIMER1_A0_VECTOR             //interrupt protocol and memory allocation
__interrupt void TIMER_A1(void)             //interrupt name
{
  P9OUT ^= BIT7;                            //toggle LED
}
