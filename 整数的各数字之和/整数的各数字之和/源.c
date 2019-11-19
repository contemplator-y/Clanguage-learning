#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：整数的各数字之和
**项目功能：输入一个非负整数，返回它各数位上的数字之和
**完成时间：2019年11月19日
*/

unsigned DigitSum(unsigned n)
{
	if (n < 10)
	{
		return n;
	}
	return n % 10 + DigitSum(n / 10);
}
 
int main()
{
	unsigned a = 9527;
	printf("%u\n", DigitSum(a));

	system("pause");
	return 0;
}