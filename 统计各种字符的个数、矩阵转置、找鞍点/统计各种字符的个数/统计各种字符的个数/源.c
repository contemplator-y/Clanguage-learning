#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void count(char * str,int * cNum,int * digitNum,
			int * blankNum,int * elseNum)
{
	for (int i = 0; *(str + i); i++)
	{
		if (isdigit(*(str + i)))
		{
			*digitNum += 1;
		}
		else if (isalpha(*(str + i)))
		{
			*cNum += 1;
		}
		else if (isspace(*(str + i)))
		{
			*blankNum += 1;
		}
		else
		{
			*elseNum += 1;
		}
	}
}
int main()
{
	int cNum = 0;
	int digitdNum = 0;
	int blankNum = 0;
	int elseNum = 0;
	char str[50];
	int i = 0;
	while (1)
	{
		char c = getchar();
		if (c != '\n')
		{
			str[i] = c;
			i++;
			continue;
		}
		break;
	}
	str[i] = '\0';
	count(str, &cNum, &digitdNum, &blankNum, &elseNum);
	printf("��ĸ�ĸ���Ϊ:%d\n", cNum);
	printf("���ֵĸ���Ϊ:%d\n", digitdNum);
	printf("�ո�ĸ���Ϊ:%d\n", blankNum);
	printf("�����ַ��ĸ���Ϊ:%d\n", elseNum);
	system("pause");
	return 0;
}