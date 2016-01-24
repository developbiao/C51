/**
@Descrie:定时器练习03
@Author:GongBiao
@Date:2016/01/10
*/

#include <reg52.h>

sbit LED = P0 ^ 0;
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

void main()
{
	unsigned char count; //计数
	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;
	
	//第一步设置定时TMOD工作模式
	TMOD = 0x01;

	//第二步设置TH0,TL0的初值
	TH0 = 0xB8;
	TL0 = 0x00;

	//第三步设置TR0 = 1 让定时器开始计时
	TR0 = 1;

	while(1)
	{
		//第四步判断TCON的TF0 == 1检查溢出情况
		if(TF0 == 1)
		{
			TF0 = 0;
			TH0 = 0xB8;
			TL0 = 0x00;
			count ++;
			if(count >= 50) // 1s
			{
				LED = ~LED;
				count = 0;
			}
		}
	}
}