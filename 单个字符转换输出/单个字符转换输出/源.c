#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：单个字符转换输出
**项目功能：键入一个字符，如果是小（大）写字符，则输出对应的大（小）写字符；如果是数字则不输出。
**完成时间：2019年11月12日
*/

int main()
{
	char c = getchar();
	if (c >= 'a' && c <= 'z')
	{
		printf("%c\n",c - 32);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		printf("%c\n", c + 32);
	}
	
	system("pause");
	return 0;
}