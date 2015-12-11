/**
@Describe:定位点亮小灯
@Author:GongBiao
@Date:2015/12/11
*/
#include <reg52.h>

sbit ADDR0 = P1^0;
sbit ADDR1 = P1^1;
sbit ADDR2 = P1^2;
sbit ADDR3 = P1^3;
sbit ENLED = P1^4;
sbit LED = P0^0;

void main()
{
	unsigned int i = 0;
	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;

	while(1)
	{
	    P0 = 0xFB;
		for(i=0; i<30000; i++);
	    P0 = 0xFF;
		for(i=0; i<30000; i++);
	}


	/*
	notepad:
	8 4 2 1 四位四位的看二进制数可计算出LED的值

	如点亮 P0 ^ 2
	1   1   1   1     1    0    1   1 

  [ 8   4  2   1]     [8    0    2   1 ]  = 0xFB

	*/
}