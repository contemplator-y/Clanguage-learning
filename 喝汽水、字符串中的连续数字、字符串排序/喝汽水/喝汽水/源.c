#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
 ����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ��
*/
int main()
{
	int empBott = 0;
	int num = 0;
	int money = 20;
	while (money || empBott == 2)
	{
		if (empBott == 2)
		{
			num++;
			empBott = 1;
		}
		else
		{
			money--;
			num++;
			empBott++;
		}
	
	}

	printf("%d\n", num);
	system("pause");
	return 0;
}