#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
��Ŀ����:����Ӹ߶�100�״�����,��غ������Ϊ��ظ߶ȵ�һ��,������,�ٷ���,���
10�����ʱ�������ľ���͵�ʮ�ε���ĸ߶�
**���ʱ��:2019��11��30��
*/


int main()
{
	double h[10] = { 100 };
	double s[10] = { 0 };
	double j[10] = { 0 };
	
	for (int i = 0; i < 10; i++)
	{
		h[i + 1] = h[i] / 2.0;
		s[i] = h[i] * 1.5;
		j[i] = h[i] / 2.0;
	}
	double sum = 0;
	for (int i = 0; i < 9; i++)
	{
		sum += s[i];
	}
	sum = sum - j[9];
	printf("%f %f\n", sum, j[9]);
	system("pause");
	return 0;
}