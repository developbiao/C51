/**
@Describe:点亮所有LED点阵小灯
@Student:GongBiao
@Date:2016/03/13
*/
#include <reg52.h>

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

void main()
{
	EA = 1;     //使能总断
	ENLED = 0;  //使能U4,选择LED点阵
	ADDR3 = 0;  //ADDR0~2需要动太改变所以不需要初始化了
	TMOD = 0x01;	//设置T0为模式1
	TH0 = 0xFC; //为T0,TH0赋初值0xFC TL0赋初值0x67,定时1ms
	TL0 = 0x67;
	ET0 = 1;   //使能T0中断
	TR0 = 1;   //启动T0
	while(1);   //程序停在这里，等待定时器中断
}

/*定时器0中断服务函数*/
void InterruptTimer0() interrupt 1
{
	static unsigned char i = 0; //动态扫描索引

	TH0 = 0xFC;		//重新加载初值
	TL0 = 0x67;
	//以下代码完成LED点阵形动态扫描刷新
	P0 = 0xFF;  //显示消隐

	switch(i)
	{
		case 0: ADDR2=0; ADDR1=0; ADDR0=0; i++; P0=0x00; break;
		case 1: ADDR2=0; ADDR1=0; ADDR0=1; i++; P0=0x00; break;
		case 2: ADDR2=0; ADDR1=1; ADDR0=0; i++; P0=0x00; break;
		case 3: ADDR2=0; ADDR1=1; ADDR0=1; i++; P0=0x00; break;
		case 4: ADDR2=1; ADDR1=0; ADDR0=0; i++; P0=0x00; break;
		case 5: ADDR2=1; ADDR1=0; ADDR0=1; i++; P0=0x00; break;
		case 6: ADDR2=1; ADDR1=1; ADDR0=0; i++; P0=0x00; break;
		case 7: ADDR2=1; ADDR1=1; ADDR0=1; i=0; P0=0x00; break;
		default:break;
	}
}
