#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int isLeap(int y)
{
	if (y % 4) 
	{
		return 0;
	}
	if (!(y % 400))
	{
		return 1;
	}
	if (y % 100)
	{
		return 1;
	}
	return 0;
}
int isOk(int y,int m,int d)
{
	if (m < 0 || m > 12 ||
		d < 0 || d > 31)
	{
		return 0;
	}
	if (m == 4 || m == 6 ||
		m == 9 || m == 11)
	{
		if (d > 30)
		{
			return 0;
		}
	}
	int f = isLeap(y);
	if (m == 2)
	{
		if (d > 28 + f)
		{
			return 0;
		}
	}
	return 1;
}

int countDays(int n,int * arr)
{
	int days = 0;
	for (int i = 0; i < n - 1; i++)
	{
		days += *(arr + i);
	}
	return days;
}
int main()
{
	int y = 0;
	int m = 0;
	int d = 0;
	while(1)
	{
		printf("请输入日期:\n");
		scanf("%d %d %d", &y, &m, &d);
		if (isOk(y, m, d))
		{
			break;
		}
		printf("您的输入有误!\n");
	}
	int f = isLeap(y);
	int month[] = { 31, 28 + f, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = countDays(m, month) + d;
	printf("是该年的第%d天\n", days);
	
	system("pause");
	return 0;
}