#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ������ַ�ת�����
**��Ŀ���ܣ�����һ���ַ��������С����д�ַ����������Ӧ�Ĵ�С��д�ַ�������������������
**���ʱ�䣺2019��11��12��
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