#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
**项目名称：三次输入密码
**项目功能：输入密码并验证，成功提示登陆成功；错误提示重新输入，最多输入三次。
**完成时间：2019年11月12日
*/

int main()
{
	char pass[] = "888888";
	char s[6];
	int n = 0;
	do
	{
		if (n == 3)
		{
			printf("您已输错三次！\n");
			break;
		}

		printf("请输入密码：");
		scanf("%s", &s);
		if (strcmp(s, pass) == 0)
		{
			printf("登陆成功！\n");
			break;
		}
		
		else
		{
			printf("输入错误!\n");
			n++;
		}
	} while (1);

	system("pause");
	return 0;
}