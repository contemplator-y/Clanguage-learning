#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：递归实现打印整数的每一位
**完成时间：2019年11月19日
*/

void Print_digit(int n)
{
	if (n > 10)
	{
		Print_digit(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	Print_digit(9527);
	system("pause");
	return 0;
}