#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ���ӡ100-200�������
**��Ŀ���ܣ�--
**���ʱ�䣺2019��11��3��
*/

int Judg_Prime(int a)
{
	int b = 2;
	for (; b < a / 2; b++)
		if (a % b == 0)
			return 0;
	return 1;

}
int main()
{
	int a = 100, n = 0;
	while (a <= 200)
	{
		if (1 == Judg_Prime(a))
		{
			printf("%d ", a);
			n += 1;
		}
		a += 1;
		if (n % 10 == 0)
			printf("\n");
	}
	system("pause");
	return 0;
}