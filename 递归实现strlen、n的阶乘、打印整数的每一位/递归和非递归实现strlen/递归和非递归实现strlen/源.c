#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：递归和非递归实现strlen
**项目名称：完成时间2019年11月19日
*/

int String_len1(char * str)
{
	if (*(str + 1) == '\0')
	{
		return 1;
	}
	return 1 + String_len1(str + 1);
}

int String_len2(char* str)
{
	int n = 1;
	for (; *(str + 1) != '\0'; str++)
	{
		n++;
	}
	return n;
}
int main()
{
	char str[] = "abcdef";
	int n1 = String_len1(str);
	int n2 = String_len2(str);
	printf("%d\n",n1);
	printf("%d\n",n2);

	system("pause");
	return 0;
}