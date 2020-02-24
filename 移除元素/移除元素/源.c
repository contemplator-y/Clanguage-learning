#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
原地移除数组nums中等于val的元素
*/
int removeElement(int* nums, int numsSize, int val){
	for (int i = 0; i < numsSize; i++){
		if (*(nums + i) == val){
			int start = numsSize - 1;
			for (; start > i; start--){
				if (*(nums + start) != val){
					*(nums + i) = *(nums + start);
					*(nums + start) = val;
					break;
				}
			}
			if (start == i){
				return i;
			}
		}
	}
	return numsSize;
}

int main(){
	int nums[] = { 3, 2, 2, 3 };
	int tmp = removeElement(nums, 4, 3);
	printf("%d\n", tmp);
	system("pause");
	return 0;
}