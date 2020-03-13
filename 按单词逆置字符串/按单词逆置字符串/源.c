#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
按照单词逆置字符串，如将"student a  am i" 转换成"i am a student"
*/

void reverseWord(char * start, char * end)
{
	int len = end - start;
	char tmp;
	for (int i = 0, j = len - 1; i < j; i++, j--)
	{
		tmp = *(start + i);
		*(start + i) = *(start + j);
		*(start + j) = tmp;
	}
}

void reverse(char * str)
{
	char * start = str;
	char * end = NULL;
	int i;
	for ( i = 0; *(str + i); i++)
	{
		if (*(str + i) == ' ')
		{
			end = str + i;
			reverseWord(start, end);
			start = str + i + 1;
		}
	}
	reverseWord(start, str + i);
	reverseWord(str, str + i);
}
int main()
{
	char str[] = "i am not caixukun";
	reverse(str);
	puts(str);
	system("pause");
	return 0;
}