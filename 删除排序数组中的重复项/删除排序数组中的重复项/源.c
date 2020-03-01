#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize){
	int flag = 0;
	for (int i = 1; i < numsSize; i++) {
		if (nums[i] != nums[flag]) {
			nums[flag + 1] = nums[i];
			flag++;
		}
	}
	return (flag + 1) * (1 && numsSize);
}

int main() {
	int nums[] = { 1, 1, 2 };
	int tmp = removeDuplicates(nums, 3);
	for (int i = 0; i < tmp; i++) {
		printf("%d ", nums[i]);
	}
	system("pause");
	return 0;
}