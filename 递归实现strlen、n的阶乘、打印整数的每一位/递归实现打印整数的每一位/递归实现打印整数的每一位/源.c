#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ��ݹ�ʵ�ִ�ӡ������ÿһλ
**���ʱ�䣺2019��11��19��
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