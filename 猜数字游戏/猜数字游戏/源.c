#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
**项目名称：猜数字游戏
**项目功能：随机生成一个1-100的整数，从键盘键入一个数字，根据提示继续输入，直至猜中为止。
**完成时间：2019年11月11日
*/

void Print_menu()
{
	printf("----------------------------\n");
	printf("---------猜数字游戏---------\n");
	printf("----------------------------\n");
	printf("输入1开始游戏，输入0结束游戏\n");

}
int main()
{
	srand(time(0));
	Print_menu();
	int tmp = 0;
	int flag = 1;
	int r = 0;
	while (flag)
	{
		printf("请输入1或者0：");
		scanf("%d", &flag);
		r = rand() % 100 + 1;
		while (flag)
		{
			printf("请输入一个整数（1-100）：");
			scanf("%d", &tmp);
			if (tmp < r)
			{
				printf("低了!\n");
			}
			else if (tmp > r)
			{
				printf("高了!\n");
			}
			else
			{
				printf("恭喜你，猜中了\n");
				break;
			}
		}
	}

	system("pause");
	return 0;
}