#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
项目功能:弹球从高度100米处降落,落地后弹起距离为落地高度的一半,再落下,再反弹,求第
10次落地时共经过的距离和第十次弹起的高度
**完成时间:2019年11月30日
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