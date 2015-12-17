/*
@Describe: ���������ƶ�������ˮ��Ч��
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
	unsigned int i = 0; //����ѭ������i�����������ʱ
	unsigned int dir = 0; //������λ�������dir
	unsigned int shift = 0x01; //����ѭ������shift ��ʼ��ֵΪ0x01
	ENLED = 0;
	ADDR3 = 1;
	ADDR2 = 1;
	ADDR1 = 1;
	ADDR0 = 0;

	while(1)
	{
	   P0 = ~shift;		 			//P0 ����ѭ����λ����ȡ��
	   for(i=0; i<20000; i++); 		//��ʱ
		if(dir == 0)  			   	//��λ�������Ϊ0ʱ������
		{
		  	shift = shift << 1;		//ѭ����λ��������1λ
			if(shift == 0x80)		//���Ƶ�����˺󣬸ı��ƶ���ʽ
			{
				dir = 1;
			}
		}
		else   						// �ƶ�����Ϊ0ʱ������
		{
			shift = shift >> 1;	    //ѭ����λ��������1λ
			if(shift == 0x01)	    //���Ƶ����Ҷ˺󣬸ı��ƶ�����
			{
				dir = 0;
			}
		}		
	}

}