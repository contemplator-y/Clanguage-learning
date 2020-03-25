#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
统计数组中位数为偶数的数字的个数。
*/
int CountNum(int n) {
	int i = 0;
	for (; n; n /= 10) {
		i++;
	}
	return i;
}
int findNumbers(int* nums, int numsSize){
	int res = 0;
	for (int i = 0; i < numsSize; i++) {
		if (CountNum(nums[i]) % 2 == 0) {
			res++;
		}
	}
	return res;
}
int main() {
	int arr[] = { 12, 345, 2, 6, 7896 };
	int res = findNumbers(arr, 5);
	printf("%d\n", res);
	system("pause");
	return 0;
}