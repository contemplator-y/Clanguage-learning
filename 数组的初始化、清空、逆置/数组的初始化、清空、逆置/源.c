#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
��Ŀ���ƣ�����ĳ�ʼ������ա�����
��Ŀ���ܣ���д����ʵ�ֶ�����ĳ�ʼ������ա�����
���ʱ�䣺2019��11��17��
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
	
	printf("ԭ���飺");
	Print_arr(a, 5);
	putchar('\n');

	printf("��պ�����飺");
	Clear_arr(a, 5);
	Print_arr(a,5);
	putchar('\n');

	printf("��ʼ�������飺");
	Init_arr(a, b, 5);
	Print_arr(a,5);
	putchar('\n');

	printf("���ú�����飺");
	Reverse_arr(a, 5);
	Print_arr(a,5);
	putchar('\n');

	system("pause");
	return 0;
}