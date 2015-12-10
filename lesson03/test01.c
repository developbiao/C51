/*
@Describe:点亮所有的小灯
@Author:GongBiao
@Date:2015/12/10
*/
#include <reg52.h>

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

sbit LED_0 = P0 ^ 0;
sbit LED_1 = P0 ^ 1;
sbit LED_2 = P0 ^ 2;
sbit LED_3 = P0 ^ 3;
sbit LED_4 = P0 ^ 4;
sbit LED_5 = P0 ^ 5;
sbit LED_6 = P0	^ 6;
sbit LED_7 = P0 ^ 7;

void main()
{
	unsigned int i = 0;
	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR2 = 1;
	ADDR0 = 0;

	while(1)
	{
		LED_0 = 0;
		LED_1 = 0;
		LED_2 = 0;
		LED_3 = 0;
		LED_4 = 0;
		LED_5 = 0;
		LED_6 = 0;
		LED_7 = 0;
		for(i=0; i<30000; i++);
		LED_0 = 1;
		LED_1 = 1;
		LED_2 = 1;
		LED_3 = 1;
		LED_4 = 1;
		LED_5 = 1;
		LED_6 = 1;
		LED_7 = 1;
		for(i=0; i<30000; i++);

	}


}