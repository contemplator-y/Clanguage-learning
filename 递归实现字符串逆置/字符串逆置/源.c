#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：递归实现字符串逆置
**完成时间：2019年11月19日
*/

void Reverse_string(char* string)
{
	//1.逆序遍历原字符串
	//2.将当前所指向的字符插入到已倒转字符串的后面
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