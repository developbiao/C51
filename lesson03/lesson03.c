/*
@Descrie: 74HC138ԭ��ѧϰ
@Author:GongBiao
@Date:2015/12/10
*/
#include <reg52.h>

sbit LED = P0^0;
sbit ADDR0 = P1^0;
sbit ADDR1 = P1^1;
sbit ADDR2 = P1^2;
sbit ADDR3 = P1^3;
sbit ENLED = P1^4;

void main()
{
	//����Ϊ������䲿��
	unsigned int i = 0; //����һ���޷������α���i,������ʼֵ0

	//����Ϊִ����䲿��
	ENLED = 0; // U3��U4��Ƭ74HC138��ʹ��     �缫+
	ADDR3 = 1; //ʹU3ʹ���������			   �缫-
	ADDR2 = 1;	 //��U3��Y6�������������Q16
	ADDR1 = 1;
	ADDR0 = 0;							   //�缫��
	
	while(1)
	{
		LED = 0;			  //����С��
		for(i=0; i<30000; i++);	  //��ʱһ��ʱ��
		LED = 1;				//Ϩ��С��
		for(i=0; i<30000; i++);	  //��ʱһ��ʱ��
	}
}


