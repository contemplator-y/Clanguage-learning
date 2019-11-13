#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：颠倒字符串
**完成时间：2019年11月12日
*/

void Reverse_string(char* s)
{
	char* left = s;
	char* right = s;
	char c;
	while (*(s + 1) != '\0')
	{
		s++;
	}
	right = s;

	while (left < right)
	{
		c = *left;
		*left = *right;
		*right = c;
		left++;
		right--;
	}
}

int main()
{
	char str[] = "abcdef";
	Reverse_string(str);
	printf("%s\n", str);

	system("pause");
	return 0;
}