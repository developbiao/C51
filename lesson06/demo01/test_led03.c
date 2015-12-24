/**
@Describe:��������LED��
@Author:GongBiao
@Date:2015/12/24
*/
#include <reg52.h>
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;
void main(void)
{
	unsigned int i = 0;	    //��ʼ��������i
	unsigned char shift = 0x01;	    // ����ƫ��
	unsigned char dir = 0;		    //�����ƶ�����

	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;

	while(1)
	{
		P0 = ~shift;
		for(i=0; i<10000; i++);     //���������ʱ

		if(dir == 0)
		{
			shift <<= 1;		        //����ƫ��
			if(shift == 0x80)
			{
				dir = 1;
			}
		}
		else
		{
			shift >>= 1;
			if(shift == 0x01)	    //����ƫ��
			{
				dir = 0;
			}
		}
	}


}