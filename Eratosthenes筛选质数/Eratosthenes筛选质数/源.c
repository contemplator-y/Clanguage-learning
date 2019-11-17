#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：Eratosthenes筛选法计算质数
**项目功能：确定一个整数上限，遍历从2到上限的整个列表，剔除不是质数的整数
**完成时间：2019年11月14日
*/

#define Size 50
int main()
{
	char arr[Size]; //整数上限为2* size - 1，下标为i对应整数2*i+1,为‘0’表示不是质数，为 ‘1’表示是质数
	for (int i = 0; i < Size; i++) 
	{
		*(arr + i) = '1';
	}
	
	int begin = 1;
	int step = 0;
	int tar = 0;
	while (begin <Size)
	{
		if (*(arr + begin) == '1')
		{
			step = 2 * begin + 1;
			tar = begin + step;
			while (tar <= Size)
			{
				*(arr + tar) = '0';
				tar += step;
			}
			begin++;
		}
		else
		{
			begin++;
		}
	}

	int n = 0;
	for (int i = 0; i < Size; i++)
	{
		if (*(arr + i) == '1')
		{
			n++;

		}
	}
	printf("质数个数为：%d\n", n);

	system("pause");
	return 0;
}