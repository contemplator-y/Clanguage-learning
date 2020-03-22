#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
给定两个正整数 x 和 y，如果某一整数等于 x^i + y^j，其中整数 i >= 0 且 j >= 0，那么我们认为该整数是一个强整数。
求小于等于bound内的所有强整数。
*/

int findNum(int*arr, int size, int tar) {
	for (int i = 0; i < size; i++) {
		if (*(arr + i) == tar) {
			return 1;
		}
	}
	return 0;
}
int* powerfulIntegers(int x, int y, int bound, int* returnSize){
	if (bound <= 1) {
		*returnSize = 0;
		return NULL;
	}
	int * res = (int*)malloc(sizeof(int) * bound);
	int s = 0, num1 = 0;
	for (int i = 1; i < bound && num1 <= 19; i *= x) {
		num1++;
		int num2 = 0;
		for (int j = 1; j < bound && num2 <= 19; j *= y) {
			num2++;
			if (i + j <= bound && findNum(res, s, i + j) == 0) {
				*(res + s) = i + j;
				s++;
			}
		}
	}
	*returnSize = s;
	return res;
}
int main() {
	int returnsize = 0;
	int* res = powerfulIntegers(2, 3, 10, &returnsize);
	for (int i = 0; i < returnsize; i++) {
		printf("%d ", *(res + i));
	}
	free(res);
	system("pause");
	return 0;
}