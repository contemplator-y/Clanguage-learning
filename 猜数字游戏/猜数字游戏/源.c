#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
**��Ŀ���ƣ���������Ϸ
**��Ŀ���ܣ��������һ��1-100���������Ӽ��̼���һ�����֣�������ʾ�������룬ֱ������Ϊֹ��
**���ʱ�䣺2019��11��11��
*/

void Print_menu()
{
	printf("----------------------------\n");
	printf("---------��������Ϸ---------\n");
	printf("----------------------------\n");
	printf("����1��ʼ��Ϸ������0������Ϸ\n");

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
		printf("������1����0��");
		scanf("%d", &flag);
		r = rand() % 100 + 1;
		while (flag)
		{
			printf("������һ��������1-100����");
			scanf("%d", &tmp);
			if (tmp < r)
			{
				printf("����!\n");
			}
			else if (tmp > r)
			{
				printf("����!\n");
			}
			else
			{
				printf("��ϲ�㣬������\n");
				break;
			}
		}
	}

	system("pause");
	return 0;
}