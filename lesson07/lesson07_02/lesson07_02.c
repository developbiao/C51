/**
@Describe:��ϰ����һ��
@Student:GongBiao
@Date:2016/03/13
*/
#include <reg52.h>
sbit ADDR0 = P1 ^ 0;
sbit ADDR1 = P1 ^ 1;
sbit ADDR2 = P1 ^ 2;
sbit ADDR3 = P1 ^ 3;
sbit ENLED = P1 ^ 4;

void main()
{
	ENLED = 0;	//U3��U4����74HC138��ʹ��
	ADDR3 = 0;	//ʹ��74ʹ֮�������
	ADDR2 = 0;	//��U4��Y1�������������Q11
	ADDR1 = 0;
	ADDR0 = 1;
	P0 = 0x00;  //��P0д��0������һ��
	while(1);	//����ֹͣ������
}