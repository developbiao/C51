/*
@Describe: 左右往复移动点亮流水灯效果
@Student:GongBiao
@Date:2015/12/17
*/

#include <reg52.h>

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

void main(void)
{
	unsigned int i = 0; //定义循环变量i，用于软件延时
	unsigned int dir = 0; //定义移位方向变量dir
	unsigned int shift = 0x01; //定义循环变量shift 初始化值为0x01
	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;

	while(1)
	{
	   P0 = ~shift;		 			//P0 等于循环移位变量取反
	   for(i=0; i<20000; i++); 		//延时
		if(dir == 0)  			   	//移位方向变量为0时，左移
		{
		  	shift = shift << 1;		//循环移位变量左移1位
			if(shift == 0x80)		//左移到最左端后，改变移动方式
			{
				dir = 1;
			}
		}
		else   						// 移动方向不为0时，右移
		{
			shift = shift >> 1;	    //循环移位变量右移1位
			if(shift == 0x01)	    //右移到最右端后，改变移动方向
			{
				dir = 0;
			}
		}		
	}

}