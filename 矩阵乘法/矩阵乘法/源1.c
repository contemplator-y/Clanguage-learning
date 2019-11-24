#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：矩阵乘法
**完成时间2019年11月22日
*/

#define ROW 3
#define COL1 2
#define COL2 3


int DetMul(int x[COL1], int y[COL1][COL2],int n)  // 行列式乘法，x与二维数组的第n列相乘
{
	int tmp[COL1] = { 0 };
	int start = 0;
	for (int i = 0; i < COL1; i++)
	{
		for (int j = 0; j < COL2; j++)
		{
			if (j == n)
			{
				tmp[start] = y[i][j];
				start++;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < COL1; i++)
	{
		sum += x[i] * tmp[i];
	}
	return sum;
}

void MatrixMul(int x[ROW][COL1], int y[COL1][COL2], int z[ROW][COL2])
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL2; col++)
		{
			
			z[row][col] = DetMul(x[row], y, col);

		}
	}
}

int main()
{
	int x[ROW][COL1] = {
			{1,2},
			{3,4},
			{5,2}
	};
	int y[COL1][COL2] = {
			{1,2,3},
			{4,2,5}
	};
	int z[ROW][COL2] = { 0 };
	MatrixMul(x, y, z);
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL2; col++)
		{
			printf("%d\t", z[row][col]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}