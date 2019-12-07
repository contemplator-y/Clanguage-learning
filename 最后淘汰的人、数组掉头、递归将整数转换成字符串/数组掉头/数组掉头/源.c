#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void func(int* arr, int n, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			int tmp = *(arr + j);
			*(arr + j) = *(arr + j - 1);
			*(arr + j - 1) = tmp;
		}
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	func(arr, 6, 2);
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", *(arr + i)); 
	}
	system("pause");
	return 0;
}