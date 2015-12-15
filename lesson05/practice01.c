#include <reg52.h>

sbit LED = P0 ^ 0;
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;


void main()
{
	unsigned char count = 0;

	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;

	//���ö�ʱ��
	TMOD = 0x01;
	TH0 = 0xB8;
	TL0 = 0x00;
	TR0 = 1;

	while(1)
	{
		if(TF0 == 1)
		{
			TF0 = 0;
			TH0 = 0xB8;
			count++;
			if(count >= 50)
			{
				count = 0;
				LED = ~LED;
			}
		}
	}
}


/*
   51��Ƭ���ľ�����11.0592M
   ����������   12 / 11059200
   x * 12 / 11059200 = 0.02s
   x = 18432

   TH0  = y

   y + x = 65536;  	���ٸ��������ڲ���ʹ��TH0���

   y = 47104;			  //��ʼ��ֵ0xB800 + 18432;
   y = 0xB800;

   */
*/