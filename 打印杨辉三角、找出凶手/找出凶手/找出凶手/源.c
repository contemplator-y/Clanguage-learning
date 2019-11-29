#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目功能：
日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
嫌疑犯的一个。以下为4个嫌疑犯的供词。
A说：不是我。    BCD
B说：是C。		C
C说：是D。		D
D说：C在胡说		ABC
已知3个人说了真话，1个人说的是假话。
现在请根据这些信息，写一个程序来确定到底谁是凶手。
**完成时间：2019年11月28日
*/

/*0111  表示A认为凶手是B或C或D
0010	表示B认为凶手是C
0001	表示C认为凶手是D
1110  表示凶手是A或B或C
*/
int main()
{
	int arr[] = { 7, 2, 1, 14 };
	for (int i = 1; i <= 4; i++)
	{
		int p = i << (4 - i);
		int tmp = 0;
		for (int j = 0; j < 4;j++)
		{
			if (p & *(arr + j))
			{
				tmp++;
			}
		}
		if (tmp == 3)
		{
			printf("%c\n", i + 'A' - 1);
			break;
		}
	}
	system("pause");
	return 0;
}