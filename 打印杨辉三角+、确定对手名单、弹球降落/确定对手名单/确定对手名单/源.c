#define _CRT_SECURE_NO_WarrRNINGS 
#include<stdio.h>
#include<stdlib.h>

/*
**项目功能:两队比赛,各出三人,甲队为ABC,乙队为XYZ
A不和X比,C不和XZ比,求三赛手的名单
**完成时间:2019年11月30日
*/

int find(char* arr, char c,int n)
{
	for (int i = 0; i <= n; i++)
	{
		if (*(arr + i) == c)
		{ 
			return 1;
		}
	}
	return 0;
}

void judgeRival(int k, char* arr, int n)
{
	if (!k)
	{
		if (*arr != 'X' && *(arr + 2) != 'X' && *(arr + 2) != 'Z')
		{
			printf("%c %c %c\n", 'A', 'B', 'C');
			printf("%c %c %c\n", *arr, *(arr+ 1), *(arr +2));

		}
		return;
	}
	for (char c = 'X'; c <= 'Z'; c++)
	{
		int tmp = find(arr, c, n);
		if (!tmp)
		{
			*(arr + n) = c;
			judgeRival(k - 1, arr, n + 1);
		}
	}
}

int main()
{
	char arr[3] = { 0 };
	judgeRival(3, arr, 0);
	system("pause");
	return 0;
}