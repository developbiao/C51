/**
@Describe: LEDTUBE ʵ�ֵ���ʱ���� 
@Author:GongBiao
@Date:2016/01/31
*/
#include <reg52.h>

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

//���������洢����ܵ���ֵ��0~9
unsigned char code LedChar[] = {
	0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
	0x80, 0x90
};

void main()
{
	unsigned char count = 0;  //��¼T0�жϴ���
	unsigned char sec = sizeof(LedChar) / sizeof(char);    //��¼����������

	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 0;
	ADDR1 = 0;
	ADDR0 = 0;
	
	TMOD = 0x01;
	TH0 = 0xB8;
	TL0 = 0x00;
	TR0 = 1;

	while(1)
	{
		if(TF0 == 1)  //�ж�50�Ƿ����
		{
			TF0 = 0;
			TH0 = 0xB8;
			TL0 = 0x00;
			count ++;
			if(count >= 10)
			{
				count = 0;
				P0 = LedChar[sec];
				sec--;
				if(sec == -1)
				{
					sec = 9;
				}
			}
		}
	}



}