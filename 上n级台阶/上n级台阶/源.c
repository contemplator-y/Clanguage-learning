#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ����:��n��̨��,һ�ο�����1~m��,��ӡ�����еĿ�����.
**���ʱ��:2019��11��25��
*/

void upStep(int n, int m,int ans,int* tar,int ord)
{
	if (ans == n) //��ӡ���
	{
		for (int i = 0; i < ord; i++)
		{
			printf("%d ", *(tar + i));
		}
		printf("\n");
	}
	else if (ans > n)

	{
		return;
	}
	for (int i = 1; i <= m; i++)
	{
		*(tar + ord) = i;
		upStep(n, m , ans + i,tar,ord + 1);
	}
}
int main()
{
	int tar[5] = { 0 };
	upStep(5, 3, 0, tar, 0);

	system("pause");
	return 0;
}