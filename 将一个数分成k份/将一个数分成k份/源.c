#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目功能:求将一个数分成k份,求以非递减的数字相加表示这个数的所有结果,如将5分成三份:
5=1+1+3,5=1+2+2
**完成时间:2019年11月25日
*/

void integerResolve(int n,int k,int start,int ord,int ans,int* tar)
{										//n为待分解的整数,k为分解的份数,
	if (k <= 0)							//start用于调整每层循环起始点。tar数组用来保存一次分解的结果
										//ord用来调节每层循环存入tar的位置
	{
		if (ans == n) // 打印一次分解结果
		{
			for (int i = 0; i < ord; i++)
			{
				printf("%d + ", *(tar + i));
			}
			printf("\b\b=%d\n",n);
		}
		return;
	}
	for (int i = start; i <= n; i++) 
	{							
		*(tar + ord) = i;
		integerResolve(n, k - 1, i ,ord + 1,ans + i,tar);
	}
}

int main()
{
	int tar[3] = { 0 };
	integerResolve(9,5,1,0,0,tar);

	system("pause");
	return 0;
}