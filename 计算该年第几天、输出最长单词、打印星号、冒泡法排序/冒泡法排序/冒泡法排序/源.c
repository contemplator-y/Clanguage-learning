#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int * arr, int n)
{
	for (int boundary = 0; boundary < n; boundary++)
	{
		for (int i = n - 1; i > boundary; i--)
		{
			if (*(arr + i) < *(arr + i - 1))
			{
				int tmp = *(arr + i);
				*(arr + i) = *(arr + i - 1);
				*(arr + i - 1) = tmp;
			}
		}
	}
}
int main()
{
	int arr[10] = { 2, 5, 5, 1, 0, 3, 8, 4, 12, 3 };
	bubbleSort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", *(arr + i));
	}

	system("pause");
	return 0;
}