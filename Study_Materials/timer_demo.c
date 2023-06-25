#include <at89c5131.h>

sbit outp = P0^7;

/////////////////////// ISR for timer 0 /////////////////////////

void timer0(void) interrupt 1
	
{
	outp = 1;  // Set P0.7 as '1'
  TR0 = 0;   // stop the timer
}

/////////////////////////////////////////////////////////////////

void  main()
{
	
	TMOD = 0x01; //mode 1 timer 0 
	ET0 = 1; //activate interrupts for timer 0
	EA = 1;  //activate global interrupts
	
	TH0 = 0xb1; // for 10ms
	TL0 = 0xe0;
	
	outp = 0;  //Initial P0.7 to '0'
	
	TR0 = 1; // start timer
	
	while(1);
		
}