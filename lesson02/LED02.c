#include <reg52.h>

sbit LED_0 = P0^0;
sbit LED_1 = P0^1;
sbit LED_2 = P0^2;
sbit ADDR0 = P1^0;
sbit ADDR1 = P1^1;
sbit ADDR2 = P1^2;
sbit ADDR3 = P1^3;
sbit ENLED = P1^4;

void main()
{
	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;
	LED_0 = 0;
	LED_1 = 0;
	LED_2 = 0;
	while(1);
}
