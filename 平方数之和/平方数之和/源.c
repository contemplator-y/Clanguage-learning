#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c。
*/
#define true 1
#define false 0
int isSquareNum(int c) {
	if ((int)sqrt(c) * (int)sqrt(c) == c) {
		return true;
	}
	return false;
}
int judgeSquareSum(int c){
	if (isSquareNum(c) == true) {
		return true;
	}
	for (int i = 1; i <= c / i; i++) {
		if (isSquareNum(c - i * i) == true) {
			return true;
		}
	}
	return false;
}
int main() {
	int c = 5;
	int res = judgeSquareSum(c);
	printf("%d\n", res);
	system("pause");
	return 0;
}