#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ����õݹ����n ��k�η�
**���ʱ�䣺2019��11��18��
*/

int Power(int n, int k)
{
	if (k == 1)
	{
		return n;
	}
	return Power(n, k - 1) * n;
}
int main()
{
	int n = 2;
	int k = 10;
	printf("n = %d,k = %d,������Ϊ��%d\n", n,k,Power(n, k));
	system("pause");
	return 0;
}