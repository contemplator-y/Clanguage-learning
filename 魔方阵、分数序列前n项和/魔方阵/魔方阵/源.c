#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：输出魔方阵，每行、每列、对角线之和均相等。
**完成时间：2019年12月1日
*/

#define N 3

void printArr(int arr[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void printMagicArr(int arr[N][N])
{
	arr[0][N / 2] = 1;
	int row = 0;
	int col = N / 2;
	for (int i = 2; i <= N * N; i++)
	{
		if (row - 1 >= 0 && col + 1 <= N - 1)
		{
			if (arr[row - 1][col + 1] != 0)
			{
				row++;
			}
			else
			{ 
				row -= 1;
				col += 1;
			}
			
		}
		else if (row - 1 >= 0)
		{
			col = 0;
			row -= 1;
		}
		else if (col + 1 <= N - 1)
		{
			row = N - 1;
			col++;
		}
		else
		{
			row += 1;
		}
		arr[row][col] = i;
	}
	printArr(arr);
}
int main()
{
	int arr[N][N] = { 0 };
	printMagicArr(arr);
	system("pause");
	return 0;
}