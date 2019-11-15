#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：判断是否为等边三角形
**项目功能：输入三个数作为三角形的边，判断是否构成三角形，进一步判断是否为等边三角形或等腰三角形
**完成时间：2019年11月4日
*/

int IS_Trian(int a,int b,int c) {
	if (a + b > c && a + c > b && b + c > a) {
		return 1;
	}
	return 0;
}

int ENOE(int a, int b, int c) {
	int n = 0;

	n = n + (a == b);
	n = n + (a == c);
	n = n + (b == c);

	return n;
}
int main() {
	int a, b, c, n;

	printf("请输入三角形的边长：\n");
	scanf("%d%d%d", &a, &b, &c);
	if (IS_Trian(a, b, c) == 1) {
		n = ENOE(a, b, c);
		switch (n) {
		case 0:
			printf("三角形为不等边三角形\n");
			break;
		case 1:
			printf("三角形为等腰三角形\n");
			break;
		case 3:
			printf("三角形为等边三角形\n");
			break;
		}
	}
	else {
		printf("该三条边不构成三角形！\n");
	}

	system("pause");
	return 0;
} 