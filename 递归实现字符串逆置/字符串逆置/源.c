#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ��ݹ�ʵ���ַ�������
**���ʱ�䣺2019��11��19��
*/

void Reverse_string(char* string)
{
	//1.�������ԭ�ַ���
	//2.����ǰ��ָ����ַ����뵽�ѵ�ת�ַ����ĺ���
	if (*(string + 1))
	{
		Reverse_string(string + 1);
	}
	char c = *string;
	while (*(string + 1))
	{
		*string = *(string + 1);
		string++;
	}
	*string = c;

}

int main()
{
	char str[] = "caixukun";
	printf("%s\n", str);

	Reverse_string(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}