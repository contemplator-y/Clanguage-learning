#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ����:��һ�����ֳ�k��,���Էǵݼ���������ӱ�ʾ����������н��,�罫5�ֳ�����:
5=1+1+3,5=1+2+2
**���ʱ��:2019��11��25��
*/

void integerResolve(int n,int k,int start,int ord,int ans,int* tar)
{										//nΪ���ֽ������,kΪ�ֽ�ķ���,
	if (k <= 0)							//start���ڵ���ÿ��ѭ����ʼ�㡣tar������������һ�ηֽ�Ľ��
										//ord��������ÿ��ѭ������tar��λ��
	{
		if (ans == n) // ��ӡһ�ηֽ���
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