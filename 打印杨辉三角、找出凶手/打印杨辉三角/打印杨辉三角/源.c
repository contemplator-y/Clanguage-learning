#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int arr[15][15] = { 0 };
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
				continue;
			}
			if (i >= 1)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j <= i; j++)
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