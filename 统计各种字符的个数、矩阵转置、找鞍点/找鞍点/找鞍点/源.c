#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 3
#define MAX_COL 3

int judgeMax(int arr[MAX_ROW][MAX_COL], int row, int col)
{
	for (int c = 0; c < MAX_COL; c++)
	{
		if (arr[row][c] > arr[row][col])
		{
			return 0;
		}
	}
	return 1;
}
int judgeMin(int arr[MAX_ROW][MAX_COL], int row, int col)
{
	for (int r = 0; r < MAX_ROW; r++)
	{
		if (arr[r][col] < arr[row][col])
		{
			return 0;
		}
	}
	return 1;
}

void find(int arr[MAX_ROW][MAX_COL], int * row, int * col)
{
	for (int r = 0; r < MAX_ROW; r++)
	{
		for (int c = 0; c < MAX_COL; c++)
		{
			int tmp1 = judgeMax(arr, r, c);
			int tmp2 = judgeMin(arr, r, c);
			if (tmp1 && tmp2)
			{
				*row = r;
				*col = c;
				return;
			}
		}
	}
	*row = -1;
	*col = -1;
}
int main()
{
	int arr[MAX_ROW][MAX_COL] =
	{
		{2,6,1},
		{4,5,0},
		{9,8,8}
	};
	int row = 0;
	int col = 0;
	find(arr, &row, &col);
	printf("%d %d\n", row, col);
	system("pause");
	return 0;
}