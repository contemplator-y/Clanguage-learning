#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：斐波那契数列
**项目功能：通过递归和非递归实现求第n个斐波那契数
**完成时间：2019年11月18日
*/

int Fibona1(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}

	return Fibona1(n - 1) + Fibona1(n - 2);

}

int Fibona2(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	int fo = 1;
	int ft = 1;
	int cur = 0;
	for (int i = 3; i <= n; i++)
	{
		cur = fo + ft;
		if (i == n)
		{
			break;
		}
		else
		{
			ft = fo;
			fo = cur;
		}
	}
	return cur;
}
int main()
{
	for (int i = 1; i < 10; i++)
	{
		printf("%d ", Fibona1(i));
	}
	printf("\n");

	for (int i = 1; i < 10; i++)
	{
		printf("%d ", Fibona2(i));
	}
	printf("\n");

	system("pause");
	return 0;
}