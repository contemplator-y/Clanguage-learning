#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
**项目名称：求数列前5项和
**项目功能：求a+aa+aaa+aaaa+aaaaa的和，a表示一个数字
*/

int Sum(int a) {
	int sum = 0;
	int temp = 0;
	for (int i = 0; i < 5; i++) {
		temp = 0;
		for (int j = 0; j <= i; j++) {
			temp = temp + pow(10, j) * a;
		}
		sum = sum + temp;
	}
	return sum;
}

int main() {
	int sum = Sum(2);
	printf("sum = %d\n", sum);
	system("pause");
	return 0;
}