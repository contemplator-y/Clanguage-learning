#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目功能:给定一个n元素数组,打印从数组中取k个数求和的所有结果(每一次中一个元素不能重复取)
**完成时间:2019年11月24日
*/

//用递归模拟多重循环
void printNum(int * src,int n,int k,int start,int ans)
{
	if (k <= 0) //选够k个元素后打印
	{
		printf("%d\n", ans);
		return;
	}
	for (int i = start; i < n; i++) // 这个循环相当于从n个元素中选择一个元素的过程,是通用的过程
	{								//循环体的作用是重复选取的过程k次
		printNum(src, n, k - 1, i + 1,ans + src[i]);
	}
}

//for (int i = 0; i < n; i++)
//{
//	for (int j = j + 1; j < n; j++)
//	{
//		for (int k = j + 1; k < n; k++)
//		{
//			printf("%d\n", *(src + i) + *(src + j) + *(src + k));
//		}
//	}
//}
int main()
{
	int src[20] = { 0 };
	int n = 0;
	scanf("%d", &n);
	int k = 0;
	scanf("%d", &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", src + i);
	}
	printNum(src, n, k, 0, 0);

	system("pause");
	return 0;
}