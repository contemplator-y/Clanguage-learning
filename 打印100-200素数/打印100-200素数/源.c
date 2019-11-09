#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：打印100-200间的素数
**项目功能：--
**完成时间：2019年11月3日
*/

int Judg_Prime(int a)
{
	int b = 2;
	for (; b < a / 2; b++)
		if (a % b == 0)
			return 0;
	return 1;

}
int main()
{
	int a = 100, n = 0;
	while (a <= 200)
	{
		if (1 == Judg_Prime(a))
		{
			printf("%d ", a);
			n += 1;
		}
		a += 1;
		if (n % 10 == 0)
			printf("\n");
	}
	system("pause");
	return 0;
}