#define _CRT_SECURE_NO_WarrRNINGS 
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ����:���ӱ���,��������,�׶�ΪABC,�Ҷ�ΪXYZ
A����X��,C����XZ��,�������ֵ�����
**���ʱ��:2019��11��30��
*/

int find(char* arr, char c,int n)
{
	for (int i = 0; i <= n; i++)
	{
		if (*(arr + i) == c)
		{ 
			return 1;
		}
	}
	return 0;
}

void judgeRival(int k, char* arr, int n)
{
	if (!k)
	{
		if (*arr != 'X' && *(arr + 2) != 'X' && *(arr + 2) != 'Z')
		{
			printf("%c %c %c\n", 'A', 'B', 'C');
			printf("%c %c %c\n", *arr, *(arr+ 1), *(arr +2));

		}
		return;
	}
	for (char c = 'X'; c <= 'Z'; c++)
	{
		int tmp = find(arr, c, n);
		if (!tmp)
		{
			*(arr + n) = c;
			judgeRival(k - 1, arr, n + 1);
		}
	}
}

int main()
{
	char arr[3] = { 0 };
	judgeRival(3, arr, 0);
	system("pause");
	return 0;
}