#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void printWord(char * start,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%c", *(start + i));
	}
}
int strLen(char * str)
{
	int i;
	for (i = 0; *(str + i); i++);
	return i;

}
int main()
{
	char str[100];
	int i = 0;
	while (1)
	{
		char c = getchar();
		if (c != '\n')
		{
			*(str + i) = c;
			i++;
			continue;
		}
		break;
	}
	*(str + i) = '\0';

	int length = 0;
	int tmp = 0;
	char * start = NULL;
	char * next = NULL;

	for (int i = 0; i <= strLen(str); i++)
	{
		if (iswalpha(*(str + i)))
		{
			tmp++;
			if (!start)
			{
				start = str + i;
			}
		}
		else
		{
			if (!length)
			{
				length = tmp;
			}
			else if(tmp > length && next)
			{
				length = tmp;
				start = next;
			}
			tmp = 0;
			if (iswalpha(*(str + i + 1)))
			{
				next = str + i + 1;
			}
		}

	}
	printWord(start, length);
	system("pause");
	return 0;
}