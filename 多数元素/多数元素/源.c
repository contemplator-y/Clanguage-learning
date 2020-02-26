#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int findExit(int * arr, int size, int tar){
	for (int i = 0; i < size; i++){
		if (*(arr + i) == tar){
			return i;
		}
	}
	return -1;
}
int majorityElement(int* nums, int numsSize){
	int * t1 = (int *)malloc(sizeof(int) * (numsSize / 2 + 1));
	int * t2 = (int *)malloc(sizeof(int) * (numsSize / 2 + 1));
	memset(t2, 0, numsSize / 2 * 4 + 4);

	int i = 0;
	for (int k = 0; k < numsSize; k++){
		int flag = findExit(t1, i, *(nums + k));
		if (flag == -1){
			*(t1 + i) = *(nums + k);
			*(t2 + i) += 1;
			i++;
		}
		else if (*(t2 + flag) == numsSize / 2){
			return *(t1 + flag);
		}
		else{
			*(t2 + flag) += 1;
		}

	}
	return *t1;
}

int main(){
	int nums[] = { 2, 3, 3 };
	int tmp = majorityElement(nums, 3);
	printf("%d\n", tmp);
	system("pause");
	return 0;
}