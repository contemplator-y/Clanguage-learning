#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目功能:上n级台阶,一次可以上1~m步,打印出所有的可能性.
**完成时间:2019年11月25日
*/

void upStep(int n, int m,int ans,int* tar,int ord)
{
	if (ans == n) //打印结果
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