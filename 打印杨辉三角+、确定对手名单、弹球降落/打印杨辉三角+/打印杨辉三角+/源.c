#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ����:���д�ӡ�������
**���ʱ��:2019��12��1��
*/

void printArr(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void printYH(int n)
{
	int arr[10] = { 1 };
	printf("1\n");
	for (int i = 1; i < 10; i++)
	{
		for (int j = i; j > 0; j--)
		{
			arr[j] += arr[j - 1];
		}
		printArr(arr, i + 1);
	}
}

int main()
{
	printYH(10);
	system("pause");
	return 0;
}