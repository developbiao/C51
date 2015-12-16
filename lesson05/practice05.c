/*
**********************************
@Describe:����ܾ�̬��ʾһλ�ַ�
@Student:GongBiao
**********************************
*/
#include <reg52.h>

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

//���������洢����ܵ���ֵ��
unsigned char code LedChar[] = {
	0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
	0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0X86, 0X8E
};
void main()
{
	unsigned char count = 0; //��¼T0�жϴ���
	unsigned char sec = 0; //��¼�����ҵ�����

	ENLED = 0;
	ADDR3 = 1; //ΪʲôADDR3����1��
	ADDR2 = 0;
	ADDR1 = 0;
	ADDR0 = 0;
	TMOD = 0x01; //����T0Ϊģʽ1
	TH0 = 0xB8; //ΪTO��ֵ0xB800
	TL0 = 0x00;
	TR0 = 1; //����T0

	while(1)
	{
		if(TF0 == 1) //�ж�T0�Ƿ����
		{
			TF0 = 0;	  //T0����� �����жϱ�־
			TH0 = 0xB8; //�����¸���ֵ
			TL0 = 0x00;
			count ++;
			
			if(count >= 50) //�ж�T0����Ƿ�ﵽ50��
			{
				count = 0;		 //�ﵽ50�κ������ֵ����
				P0 = LedChar[sec];	//ÿ�����һ��LED��ֵ������
				sec++;
				if(sec >= 16)
				{
					sec = 0;
				}
			}
		}
	}

}