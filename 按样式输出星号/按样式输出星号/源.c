#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：按样式输出星号
**完成时间：2019年11月9日
*/

void Star(int n) {
	for (int i = 0; i < n; i++) {
		printf("%c", '*');
	}
	printf("\n");
}//打印一行n个星号

void Print_star(int max) {
	for (int i = 1; i < 2 * max; i++) {
		if (i % 2 == 0) {
			printf("\n");
		}
		else if (i <= max) {
				Star(i);
		}
			else {
				Star(2 * max - i);
		}
	}
}//max为一行星号的最大值，每两行星号间空一行

int main() {
	Print_star(13);

	system("pause");
	return 0;
}