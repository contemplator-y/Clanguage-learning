#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int missingNumber(int* nums, int numsSize){
	int sum = numsSize * (numsSize + 1) / 2;
	for (int i = 0; i < numsSize; i++) {
		sum -= nums[i];
	}
	return sum;
}

int main() {
	int nums[] = { 0, 4, 1, 2, 3, 5, 7 };
	int tmp = missingNumber(nums, 7);
	printf("%d\n", tmp);
	system("pause");
	return 0;
}