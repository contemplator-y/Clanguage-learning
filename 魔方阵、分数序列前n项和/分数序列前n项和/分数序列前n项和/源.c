#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目功能:计算2/1 3/2 5/3..的前n项和
*/
int main()
{
	double a[20] = { 0 };
	double b[20] = { 0 };
	a[0] = 2;
	b[0] = 1;
	for (int i = 1; i < 20; i++)
	{
		a[i] = a[i - 1] + b[i - 1];
		b[i] = a[i - 1];
	}
	double sum = 0.0f;
	for (int i = 0; i < 20; i++)
	{
		sum += a[i] / b[i];
	}
	printf("%f\n", sum);
	system("pause");
	return 0;
}