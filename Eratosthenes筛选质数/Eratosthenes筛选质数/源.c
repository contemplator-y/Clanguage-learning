#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ�Eratosthenesɸѡ����������
**��Ŀ���ܣ�ȷ��һ���������ޣ�������2�����޵������б��޳���������������
**���ʱ�䣺2019��11��14��
*/

#define Size 50
int main()
{
	char arr[Size]; //��������Ϊ2* size - 1���±�Ϊi��Ӧ����2*i+1,Ϊ��0����ʾ����������Ϊ ��1����ʾ������
	for (int i = 0; i < Size; i++) 
	{
		*(arr + i) = '1';
	}
	
	int begin = 1;
	int step = 0;
	int tar = 0;
	while (begin <Size)
	{
		if (*(arr + begin) == '1')
		{
			step = 2 * begin + 1;
			tar = begin + step;
			while (tar <= Size)
			{
				*(arr + tar) = '0';
				tar += step;
			}
			begin++;
		}
		else
		{
			begin++;
		}
	}

	int n = 0;
	for (int i = 0; i < Size; i++)
	{
		if (*(arr + i) == '1')
		{
			n++;

		}
	}
	printf("��������Ϊ��%d\n", n);

	system("pause");
	return 0;
}