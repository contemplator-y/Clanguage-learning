#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int countOne(int n){
	int sum = 0;
	for (; n; n >>= 1) {
		sum += n % 2;
	}
	return sum;
}
int* sortByBits(int* arr, int arrSize, int* returnSize){
	int *res = malloc(sizeof(int) * arrSize);
	for (int i = 0; i < arrSize - 1; i++) {
		for (int j = i + 1; j < arrSize; j++) {
			int c1 = countOne(*(arr + i));
			int c2 = countOne(*(arr + j));
			if (c1 > c2 || c1 == c2 && arr[i] > arr[j]) {
				int tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
			}
		}
	}
	for (int i = 0; i < arrSize; i++) {
		*(res + i) = *(arr + i);
	}
	*returnSize = arrSize;
	return res;
}
int main() {
	int nums[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	int returnSize = 0;
	int *res = sortByBits(nums, 9, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", *(res + i));
	}
	system("pause");
	return 0;
}