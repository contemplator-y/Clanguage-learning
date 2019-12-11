#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void strSort(char ** arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int tmp = strcmp(*(arr + i), *(arr + j));
			if (tmp > 0)
			{
				char * p = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = p;
			}
		}
	}
}
int main()
{
	char * str[] = { "abcd", "hgsea", "age", "tga" };
	strSort(str, 4);
	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", *(str + i));
	}
	system("pause");
	return 0;
}