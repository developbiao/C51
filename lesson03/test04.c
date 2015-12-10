/*
@Describe:练习点亮小灯
@Author:GongBiao
@Date:2015/12/10
*/
#include <reg52.h>

sbit ADDR0 = P1^0;
sbit ADDR1 = P1^1;
sbit ADDR2 = P1^2;
sbit ADDR3 = P1^3;
sbit ENLED = P1^4;

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
			//通过地址操作
		  P0 = 0xFE;
		  for(i=0; i<30000; i++);
		  P0 = 0xFD;
		  for(i=0; i<30000; i++)
		  P0 = 0xEF;
		  for(i=0; i<30000; i++);
	}
}