#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void func(int n, char* str, int i)
{
	if (!n)
	{
		return;
	}
	func(n / 10, str, i - 1);
	*(str + i) = n % 10 + '0';
}
int main()
{
	char str[20] = { 0 };
	func(9527, str, 3);
	printf("%s\n", str);
	system("pause");
	return 0;
}