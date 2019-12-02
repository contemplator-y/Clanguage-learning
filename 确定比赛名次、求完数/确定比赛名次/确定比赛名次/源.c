#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
**项目功能:
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
A选手说：B第二，我第三；		b2a3
B选手说：我第二，E第四；		b2e4
C选手说：我第一，D第二；		c1d2
D选手说：C最后，我第三；		c5d3
E选手说：我第四，A第一；		e4a1
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。 
**完成时间:2019年11月28日
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
			printf("A-E对应的名次为:\n");
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
	int ord[5] = {0};//A-E的比赛名次
	judgeOrd(5, ord);
	system("pause");
	return 0;
}