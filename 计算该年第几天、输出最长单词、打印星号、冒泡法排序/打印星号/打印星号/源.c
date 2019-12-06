#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void printStar()
{
	printf("* * * * *\n");
}

void printBlank(int n)
{
	for (int i = 1; i <= n; i++)
	{
		printf("  ");
	}
}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		if (i)
		{
			printBlank(i);
		}
		printStar();
	}
	system("pause");
	return 0;
}