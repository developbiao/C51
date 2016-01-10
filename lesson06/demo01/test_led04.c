/**
@Deccrie:2016年继续学习单片机
@Author:GongBiao
@Date:2016/01/10
*/

#include <reg52.h>
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

void main(void)
{
	unsigned int i = 0; //初始化计数器i
	unsigned char shift = 0x01; //定义偏移
	unsigned char dir = 0;  //定义移动方向

	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;

	while(1)
	{
		P0 = ~shift;
		for(i=0; i<60000; i++); //用于软件延时

		if(dir == 0)
		{
			shift <<= 1;	   //左移
			if(shift == 0x80)
			{
				dir = 1;
			}

		}
		else
		{
			shift >>= 1;		   //左移
			if(shift == 0x01)
			{
				dir = 0;
			}
		}
	}
}