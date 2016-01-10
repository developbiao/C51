/**
@Describe:��ʱ��ԭ��
@Student:GongBiao
@Date:2016/01/10
*/
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

	//��һ�����������⹦�ܼ�����TMOD
	TMOD = 0x01;

	//�ڶ������ü����Ĵ���TH0��TL0��ֵ
	TH0 = 0xB8;
	TL0 = 0x00;

	//����������TR0 =1 �ö�ʱ����ʼ��ʱ
	TR0 = 1;
	
	while(1)
	{
	
		//���Ĳ��жϼ�����TF0λ����ⶨʱ��������
		if(TF0 == 1)
		{
			TF0 = 0;
			TH0 = 0xB8;
			TL0 = 0x00;
			count++;
			if(count >= 50)
			{
				count = 0;
				LED = ~LED;
			}
		}

		 
	}
																   
		//x * 12 / 111059200 = 0.02	 
		//һ������������18432
}