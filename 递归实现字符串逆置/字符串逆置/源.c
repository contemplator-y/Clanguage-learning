#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ��ݹ�ʵ���ַ�������
**���ʱ�䣺2019��11��19��
*/

void Reverse_string(char* string)
{
	//�������
	//����ǰ��ָ����ַ����뵽���������ַ����ĺ���
	if (*(string + 1) != '\0')
	{
		Reverse_string(string + 1);
	}
	char c = *string;
	while (*(string + 1) != '\0')
	{
		*string = *(string + 1);
		string++;
	}
	*string = c;

}

int main()
{
	char str[] = "abcdef";
	printf("%s\n", str);

	Reverse_string(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}