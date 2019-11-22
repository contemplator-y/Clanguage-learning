#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：冒泡法排序
**完成时间：2019年11月21日
*/

void Bubblesort(int* arr,int n)
{
	for (int bound = 0; bound < n; bound++)
	{
		for (int start = n - 1; start > bound; start--)
		{
			if (*(arr + start) < *(arr + start - 1))
			{
				int tmp = *(arr + start);
				*(arr + start) = *(arr + start - 1);
				*(arr + start - 1) = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 2,6,1,8,4 };
	Bubblesort(arr,5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", *(arr + i));
	}

	system("pause");
	return 0;
}