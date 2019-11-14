#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define Tar 9
#define Max 100

/*
**项目名称:统计9的个数
**项目功能:统计1-100整数中9出现的次数
**完成时间:2019年11月6日
*/

int Count(int m ,int n) {
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		if (i / 10 == n) {
			sum++;
		}
		if(i % 10 == n) {
			sum++;
		}
	}
	return sum;
}

int main() {
	printf("%d以内%d的个数为:%d\n", Max, Tar,Count(Max,Tar));

	system("pause");
	return 0;
}