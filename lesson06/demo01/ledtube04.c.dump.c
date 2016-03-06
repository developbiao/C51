/**
@Describe:数码管动态显示
@Student:GongBiao
@Date:2016/01/31
*/
#include <reg52.h>

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

unsigned char code LedChar[] = { //数码管显示字符转换表
	0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
	0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E
};
unsigned char LedBuff[6] = {   //数码管显示缓冲区，初值0xFF确保启动都不亮
	0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
void main()
{
	unsigned char i = 0; //动态扫描索引
	unsigned int count = 0; //记录T0中断次数
	unsigned long sec = 0; //记录经过的秒数

	ENLED = 0;	 //使能U3,选择控制数码管
	ADDR3 = 1; //因为需要动态改变ADDR0-2的值，所以不需要初始化了
	TMOD = 0x01; //设置T0为模式1
	TH0 = 0xFC;  //为TO赋初值0xFC(67),定时1ms
	TL0 = 0x67; 
	TR0 = 1;   //启动T0

	while(1)
	{
			if(TF0 == 1)   //判断T0是否溢出
			{
				TF0 = 0;   //T0溢出后，清零中断标志
				TH0 = 0xFC;  //并重新赋初值
				TL0 = 0x67;
				count++;   //计数值自加1
				if(count >= 1) //判断T0溢出是否达到1000次
				{
					count = 0 ; //达到1000次后计数值清零
					sec++; //秒计数自加1
					//以下代码将sec按十进制位从低到高依次提取并转为数码管显示字符
					LedBuff[0] = LedChar[sec % 10];
					LedBuff[1] = LedChar[sec / 10 % 10];
					LedBuff[2] = LedChar[sec / 100 % 10];
					LedBuff[3] = LedChar[sec / 1000 % 10];
					LedBuff[4] = LedChar[sec / 10000 % 10];
					LedBuff[5] = LedChar[sec / 100000 % 10];

				}
				//以下代码完成数码管动态扫描刷新
				P0 = 0xFF; //解决鬼影问题
				switch(i)
				{
					case 0: ADDR2=0; ADDR1 = 0; ADDR0 = 0; i++; P0 = LedBuff[0];break;
					case 1: ADDR2=0; ADDR1 = 0; ADDR0 = 1; i++; P0 = LedBuff[1];break;
					case 2: ADDR2=0; ADDR1 = 1; ADDR0 = 0; i++; P0 = LedBuff[2];break;
					case 3: ADDR2=0; ADDR1 = 1; ADDR0 = 1; i++; P0 = LedBuff[3];break;
					case 4: ADDR2=1; ADDR1 = 0; ADDR0 = 0; i++; P0 = LedBuff[4];break;
					case 5: ADDR2=1; ADDR1 = 0; ADDR0 = 1; i=0; P0 = LedBuff[5];break;
					default: break;

				}
			}
	}
}