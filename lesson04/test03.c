/*
@Descrie:右移点亮LED
@Author:GongBiao
@Date:2015/12/11
*/
#include <reg52.h>

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

void main()
{
 unsigned int i = 0;
 unsigned char count = 0;

   ENLED = 0;
   ADDR3 = 1;
   ADDR2 = 1;
   ADDR1 = 1;
   ADDR0 = 0;

   while(1)
   {
   
   		//有逻辑错误的代码	
   		if(count <= 0)
		{
   			P0 = ~(0x80 >> count);
			count++;
		}

		else if(count >= 8)
		{
			P0 = ~(0x01 << count);
			count--;
		}
		else
		{
			P0 = ~(0x80 >> count);
			count++;
		}


		for(i=0; i<30000; i++);		

   }

  
}