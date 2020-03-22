#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
自除数是可以被包含的每一位数除尽的数。求[left,right]内的所有自除数。
*/
#define true 1
#define false 0

int isDividingNum(int n) {
	for (int i = n; i; i /= 10) {
		int tmp = i % 10;
		if (tmp == 0 || n % tmp != 0) {
			return 0;
		}
	}
	return 1;
}
int* selfDividingNumbers(int left, int right, int* returnSize){
	int* res = (int*)malloc(sizeof(int) * (right - left + 1));
	int s = 0;
	for (int i = left; i <= right; i++) {
		int tmp = isDividingNum(i);
		if (tmp == true) {
			*(res + s) = i;
			s++;
		}
	}
	*returnSize = s;
	return res;
}
int main() {
	int returnSize = 0;
	int* res = selfDividingNumbers(1, 22, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", *(res + i));
	}
	free(res);
	system("pause");
	return 0;
}