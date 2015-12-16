/*
**********************************
@Describe:数码管静态显示一位字符
@Student:GongBiao
**********************************
*/
#include <reg52.h>

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

//用数组来存储数码管的真值表
unsigned char code LedChar[] = {
	0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
	0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0X86, 0X8E
};
void main()
{
	unsigned char count = 0; //记录T0中断次数
	unsigned char sec = 0; //记录经过我的秒数

	ENLED = 0;
	ADDR3 = 1; //为什么ADDR3等于1？
	ADDR2 = 0;
	ADDR1 = 0;
	ADDR0 = 0;
	TMOD = 0x01; //设置T0为模式1
	TH0 = 0xB8; //为TO赋值0xB800
	TL0 = 0x00;
	TR0 = 1; //启动T0

	while(1)
	{
		if(TF0 == 1) //判断T0是否溢出
		{
			TF0 = 0;	  //T0溢出后， 清零中断标志
			TH0 = 0xB8; //并重新赋初值
			TL0 = 0x00;
			count ++;
			
			if(count >= 50) //判断T0溢出是否达到50次
			{
				count = 0;		 //达到50次后计数器值清零
				P0 = LedChar[sec];	//每秒遍历一个LED真值到这里
				sec++;
				if(sec >= 16)
				{
					sec = 0;
				}
			}
		}
	}

}