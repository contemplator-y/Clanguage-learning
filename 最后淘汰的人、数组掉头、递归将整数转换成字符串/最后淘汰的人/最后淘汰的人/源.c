#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**n个人围坐一圈，1-3报数，报到3的人退出，求最后一个人。
*/

#define N 7
int find(int* arr, int n, int tar)
{
	for (int i = 0; i < n; i++)
	{
		if (*(arr + i) == tar)
		{
			return i;
		}
	}
	return -1;
}

int sum(int* arr, int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += *(arr + i);
	}
	return s;
}

void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}
int main()
{
	int arr[N] = { 0 };
	int i = 1;
	int j = 0;
	while (sum(arr, N) < N - 2)
	{
		i++;
		while (1)
		{
			j++;
			if (j == N)
			{
				j = 0;
			}
			if (*(arr + j) == 0)
			{
				break;
			}
		}
		
		if (i == 3)
		{
			i = 0;
			*(arr + j) = 1;
			printArr(arr, N);
		}
	}
	int tmp = find(arr, N, 0);
	printf("%d\n", tmp);
	system("pause");
	return 0;
}