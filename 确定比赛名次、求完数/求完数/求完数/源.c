#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void isPerfectNum(int n)
{
	int tmp = n;
	int arr[1000] = { 0 };
	int j = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			tmp = tmp - i;
			arr[j] = i;
			j++;
		}
	}
	if (!tmp)
	{
		printf("%d=", n);
		for (int i = 0; i < j; i++)
		{
			printf("%d,", *(arr + i));
		}
		printf("\n");
	}

}
int main()
{
	for (int i = 1; i < 1001; i++)
	{
		 isPerfectNum(i);

	}
	system("pause");
	return 0;
}