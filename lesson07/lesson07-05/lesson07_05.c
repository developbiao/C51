/**
@Describe:向上滚动的I lOVE YOU
@Student:GongBiao
@Date:2016/03/13  18:20
*/
#include <reg52.h>
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

unsigned char code image[] = { //图片的字模表
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xC3,0xE7,0xE7,0xE7,0xE7,0xE7,0xC3,0xFF,
	0x99,0x00,0x00,0x00,0x81,0xC3,0xE7,0xFF,
	0x99,0x99,0x99,0x99,0x99,0x81,0xC3,0xFF,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF
};

void main()
{							   
	EA = 1;  	//使能总中断
	ENLED = 0;  //使能U4，选择LED点阵
	ADDR3 = 0;
	TMOD = 0x01; //设置T0为模式1
	TH0 = 0xFC; 	  //为T0赋初值0xFC67,定时1ms
	TL0 = 0x67;
	ET0 = 1;  //使能T0中断
	TR0 = 1;   //启动T0
	while(1);
}

/*定时器0中断服务函数*/
void InterruptTimer0() interrupt 1
{
	  static unsigned char i = 0; //动态扫描的索引
	  static unsigned char timer = 0; // 250ms软件定时器
	  static unsigned char index = 0; //图片刷新索引

	  TH0 = 0xFC;		//重新加载初值
	  TL0 = 0x67;

	  //以下代码完成LED点阵动态扫描刷新
	  P0 = 0xFF;  //显示消隐
	  switch(i)
	  {
	  	case 0: ADDR2=0; ADDR1=0; ADDR0=0; i++; P0=image[index + 0]; break;
		case 1: ADDR2=0; ADDR1=0; ADDR0=1; i++; P0=image[index + 1]; break;
		case 2: ADDR2=0; ADDR1=1; ADDR0=1; i++; P0=image[index + 2]; break;
		case 3: ADDR2=0; ADDR1=1; ADDR0=0; i++; P0=image[index + 3]; break;
		case 4: ADDR2=1; ADDR1=0; ADDR0=0; i++; P0=image[index + 4]; break;
		case 5: ADDR2=1; ADDR1=0; ADDR0=1; i++; P0=image[index + 5]; break;
		case 6: ADDR2=1; ADDR1=1; ADDR0=0; i++; P0=image[index + 6]; break;
		case 7: ADDR2=1; ADDR1=1; ADDR0=1; i=0; P0=image[index + 7]; break;
		default: break;
	  }

	  //以下代码完成每250ms改变一帧图像
	  timer++;
	  if(timer >= 250) //达到250ms时改变一次图片索引
	  {
	  	timer = 0;
		index ++;
		if(index >= 32) //图片索引到达到了32后归零
		{
			index = 0;
		}						 
	  }

}

