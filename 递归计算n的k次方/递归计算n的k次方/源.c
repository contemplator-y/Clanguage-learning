#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：利用递归计算n 的k次方
**完成时间：2019年11月18日
*/

int Power(int n, int k)
{
	if (k == 1)
	{
		return n;
	}
	return Power(n, k - 1) * n;
}
int main()
{
	int n = 2;
	int k = 10;
	printf("n = %d,k = %d,计算结果为：%d\n", n,k,Power(n, k));
	system("pause");
	return 0;
}