/**
@Describe:��ˮ��������ϰ
@Author:GongBiao
@Date:2015/12/11
*/
#include <reg52.h>

sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1	^ 3;
sbit ENLED = P1 ^ 4;


void main()
{
	unsigned int i = 0; //����ѭ������i, ���������ʱ
	unsigned int count = 0; //�����������count,������λ����
	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;

	while(1)
	{
		P0 = ~(0x001 << count); //P0����1����countλ������8��С��
		for(i=0; i<20000; i++); //�����ʱ
		count ++;
		if(count >= 8)
			count = 0;

	}




}