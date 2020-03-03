#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int func(int n)
{
	int tmp = 0;
	for (int i = n, j = 0; i; i /= 16, j++)
	{
		tmp += i % 16 * (int)pow(16, j);
	}
	return tmp;
}
int main()
{
	int n = 0;
	scanf("%x", &n);
	int tmp = func(n);
	printf("%d\n", n);
	system("pause");
	return 0;
}