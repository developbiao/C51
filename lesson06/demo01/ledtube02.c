#include <reg52.h>

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;


//用数组来存储数码管的真值表0~F
unsigned char code LedChar[] = {
	0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
	0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E
};

void main()
{	
	unsigned char count = 0;  //记录T0中断次数
	unsigned char sec = 0;	   //记录经过的秒数
						  
	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 0;
	ADDR1 = 0;
	ADDR0 = 0;

	//设置定时器
	TMOD = 0x01;
	TH0  = 0xB8;
	TL0  = 0x00;
	TR0  = 1;  //启动T0

	while(1)
	{
		if(TF0 == 1)
		{
			TF0 = 0;
			TH0 = 0xB8;
			TL0 = 0x00;
			count++;
		}
		if(count >= 50)	 //判断T0溢出是否达到50次
		{
			count = 0;	   //达到50次后计数值清零
			P0 = LedChar[sec];   //当前秒数对应的真值表值送达P0口
			sec++;
			if(sec >= 16)	  // 当0xF(后)重新开始
			{
				sec = 0;
			}
		}
	}

}