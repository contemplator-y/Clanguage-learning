#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ��ߵ��ַ���
**���ʱ�䣺2019��11��12��
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