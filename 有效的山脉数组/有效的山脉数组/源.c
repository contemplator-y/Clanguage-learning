#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define false 0
#define true 1

int findTop(int *arr, int start, int end, int flag){
	while (start * flag <= flag * end){
		if (*(arr + start) >= *(arr + flag + start)){
			return start;
		}
		start += flag;
	}
	return start + 1;
}
int validMountainArray(int* A, int ASize){
	if (ASize < 3){
		return false;
	}
	int left = findTop(A, 0, ASize - 2, 1);
	if (left == 0 || left == ASize - 1){
		return false;
	}
	int right = findTop(A, ASize - 1, 1, -1);
	if (right == left){
		return true;
	}
	return false;
}

int main(){
	int nums[] = { 0, 2, 4, 2, 1 };
	int tmp = validMountainArray(nums, 5);
	printf("%d\n", tmp);
	system("pause");
	return 0;

}