#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

/*
**项目名称:数组互换
**项目功能:交换两个数组中的内容
**完成时间:2019年11月5日
*/

void Exchange(int a[], int b[]) {
	int c = 0;
	for (int i = 0; i < SIZE; i++) {
		c = a[i];
		a[i] = b[i];
		b[i] = c;
	}
}

int main() {
	int a[SIZE], b[SIZE];

	printf("请输入两组数(每组5个)：\n");
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &b[i]);
	}

	Exchange(a, b);

	printf("交换后的结果为：\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", b[i]);
	}
	
	system("pause");
	return 0;
}