#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：递归和非递归实现n的阶乘
**完成时间2019年11月19日
*/

int Facto1(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n * Facto1(n - 1);
}

int Facto2(int n)
{
	int res = 1;
	for (int i = 1; i <= n; i++)
	{
		res *= i;
	}
	return res;
}

int main()
{
	int n = 6;
	int res1 = Facto1(n);
	int res2 = Facto2(n);
	printf("%d\n", res1);
	printf("%d\n", res2);

	system("pause");
	return 0;
}