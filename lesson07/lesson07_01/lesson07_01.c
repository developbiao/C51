/**
@Describe:����һ��LED����С��
@Student:GongBiao
@Date:2016/03/13
*/
#include <reg52.h>

sbit LED = P0 ^ 3; 	//������4��С��
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;	  
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

void main()
{
	ENLED = 0; //U3��U4����74HC138��ʹ��
	ADDR3 = 0; //ʹ��U4ʹ֮�������
	ADDR2 = 1; //��U4��Y0�������������Q13
	ADDR1 = 0;
	ADDR0 = 0;
	LED = 0; //��P0.0д��0 ���������Ͻǵ�һ����
	while(1); //�����ֹͣ������
}