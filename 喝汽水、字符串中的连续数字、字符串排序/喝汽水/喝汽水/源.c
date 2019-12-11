#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
 喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。
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