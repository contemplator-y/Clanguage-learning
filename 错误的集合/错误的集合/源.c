#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
在1-n构成的数组中,找出某个出现两次和缺少的元素
*/

int* findErrorNums(int* nums, int numsSize, int* returnSize){
	int * res = malloc(sizeof(int) * 2);
	for (int i = 0; i < numsSize; i++){
		int t = *(nums + i) % numsSize;
		*(nums + t) += numsSize;
	}
	if (*nums <= numsSize){
		*(res + 1) = numsSize;
	}
	else if (*nums > 2 * numsSize){
		*res = numsSize;
	}
	for (int i = 1; i < numsSize; i++){
		if (*(nums + i) > 2 * numsSize){
			*res = i;
		}
		else if (*(nums + i) <= numsSize){
			*(res + 1) = i;
		}
	}
	*returnSize = 2;
	return res;
}

int main(){
	int nums[] = { 1, 3, 5, 2, 2 };
	int returnSize = 0;
	int *res = findErrorNums(nums, 5, &returnSize);
	printf("%d %d\n", *res, *(res + 1));
	system("pause");
	return 0;
}