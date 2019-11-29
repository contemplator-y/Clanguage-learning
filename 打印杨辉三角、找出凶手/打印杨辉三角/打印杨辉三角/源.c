#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
打印杨辉三角
1
1 1
1 2 1
1 3 3 1

完成时间：2019年11月28日
*/

int main()
{
	int arr[15][15] = { 0 };
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (j == 0 || j == i)
			{
				arr[i][j] = 1;
			}
			if (j < i && j > 0)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
			if (j == i)
			{
				break;
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (arr[i][j] != 0)
			{
				printf("%d ", arr[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");

	system("pause");
	return 0;
}