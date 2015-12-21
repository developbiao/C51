#include <reg52.h>

void main()
{

}

void InterruptTimer0() interrupt 1
{
	TH0 = 0xFC;
	TL0 = 0x67;
	count ++;
	P0 = 0xFF;
}