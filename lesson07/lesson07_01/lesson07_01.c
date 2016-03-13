/**
@Describe:点亮一个LED点阵小灯
@Student:GongBiao
@Date:2016/03/13
*/
#include <reg52.h>

sbit LED = P0 ^ 3; 	//点亮第4点小灯
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;	  
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

void main()
{
	ENLED = 0; //U3、U4两处74HC138总使能
	ADDR3 = 0; //使能U4使之正常输出
	ADDR2 = 1; //经U4的Y0输出开启三极管Q13
	ADDR1 = 0;
	ADDR0 = 0;
	LED = 0; //向P0.0写入0 来点亮左上角的一个点
	while(1); //向程序停止在这里
}