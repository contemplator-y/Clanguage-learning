#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
��Ŀ����:ʵ�־����ת��
**���ʱ��:2019��12��4��
*/

void transpose(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i > j)
			{
				int tmp = arr[i][j];
				arr[i][j] = arr[j][i];
				arr[j][i] = tmp;
			}
		}
	}
}
int main()
{
	int arr[3][3] = 
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	transpose(arr);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}