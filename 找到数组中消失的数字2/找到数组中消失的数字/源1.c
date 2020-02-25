#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
	int * res = (int *)malloc(sizeof(int) * numsSize);
	if (!numsSize){
		*returnSize = 0;
		return res;
	}
	for (int i = 0; i < numsSize; i++){
		nums[nums[i] % numsSize] += numsSize;
	}
	int n = 0;
	if (*nums <= numsSize){
		*(res + n) = numsSize;
		n++;
	}
	for (int i = 1; i < numsSize; i++){
		if (*(nums + i) <= numsSize){
			*(res + n) = i;
			n++;
		}
	}
	*returnSize = n;
	return res;
}

int main(){
	int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
	int returnSize = 0;
	int *res = findDisappearedNumbers(nums, 8, &returnSize);
	for (int i = 0; i < returnSize;i++){
		printf("%d ", *(res + i));
	}
	printf("\n");
	system("pause");
	return 0;
}