#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
**��Ŀ����:
5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
Aѡ��˵��B�ڶ����ҵ�����		b2a3
Bѡ��˵���ҵڶ���E���ģ�		b2e4
Cѡ��˵���ҵ�һ��D�ڶ���		c1d2
Dѡ��˵��C����ҵ�����		c5d3
Eѡ��˵���ҵ��ģ�A��һ��		e4a1
����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ� 
**���ʱ��:2019��11��28��
*/

int isExit(int num, int * ord,int n)
{
	for (int i = 0; i < n; i++)
	{
		if (*(ord + i) == num)
		{
			return 1;
		}
	}
	return 0;
}
void judgeOrd(int k,int * ord)
{
	if (!k)
	{
		if (   ((ord[1] == 2) + (ord[0] == 3) == 1)
			&& ((ord[1] == 2) + (ord[4] == 4) == 1)
			&& ((ord[2] == 1) + (ord[3] == 2) == 1)
			&& ((ord[2] == 5) + (ord[3] == 3) == 1)
			&& ((ord[4] == 4) + (ord[0] == 1) == 1)
			)
		{
			printf("A-E��Ӧ������Ϊ:\n");
			for (int i = 0; i < 5; i++)
			{
				printf("%d ", ord[i]);
			}
		}
		return;
			
	}
	int n = 5 - k;
	for (int i = 1; i <= 5; i++)
	{
		int tmp = isExit(i, ord, n + 1);
		if (!tmp)
		{
			*(ord + n) = i;
			judgeOrd(k - 1, ord);
		}
	}
}

int main()
{
	int ord[5] = {0};//A-E�ı�������
	judgeOrd(5, ord);
	system("pause");
	return 0;
}