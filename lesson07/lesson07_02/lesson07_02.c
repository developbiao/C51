/**
@Describe:练习点亮一行
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
	ENLED = 0;	//U3、U4两处74HC138总使能
	ADDR3 = 0;	//使能74使之正常输出
	ADDR2 = 0;	//经U4的Y1输出开启三极管Q11
	ADDR1 = 0;
	ADDR0 = 1;
	P0 = 0x00;  //向P0写入0来点亮一行
	while(1);	//程序停止在这里
}