#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ������ĸ�����֮��
**��Ŀ���ܣ�����һ���Ǹ�����������������λ�ϵ�����֮��
**���ʱ�䣺2019��11��19��
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