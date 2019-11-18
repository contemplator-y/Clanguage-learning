#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
项目名称：数组的初始化、清空、逆置
项目功能：编写函数实现对数组的初始化、清空、逆置
完成时间：2019年11月17日
*/

void Clear_arr(int * a, int n)
{
	memset(a, 0, sizeof(int) * n);
}

void Swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void Init_arr(int* a, int* b, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(a + i) = *(b + i);
	}
}

void Print_arr(int * a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(a + i));
	}
}

void Reverse_arr(int * a, int n)
{
	for (int i = 0, j = n - 1; i < j; i++, j--)
	{
		Swap(a + i, a + j);
	}
}

int main()
{
	int a[5] = {6,7,8,9,10};
	int b[5] = { 1, 2, 3, 4, 5 };
	
	printf("原数组：");
	Print_arr(a, 5);
	putchar('\n');

	printf("清空后的数组：");
	Clear_arr(a, 5);
	Print_arr(a,5);
	putchar('\n');

	printf("初始化后数组：");
	Init_arr(a, b, 5);
	Print_arr(a,5);
	putchar('\n');

	printf("逆置后的数组：");
	Reverse_arr(a, 5);
	Print_arr(a,5);
	putchar('\n');

	system("pause");
	return 0;
}