#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

void reorderOddEven(int* arr, int size) {
	if (arr == NULL || size <= 0) {
		return; 
	}
	int left = 0, right = size - 1;
	while (left < right) {
		while (left < right && arr[left] % 2 == 1) {
			left++;
		}
		while (left < right && arr[right] % 2 == 0) {
			right--;
		}
		if (left < right) {
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
int isEven(int n) {
	return (n & 1) == 0;
}
void reorder(int* arr, int size, int(*func)(int)) {
	if (arr == NULL || size <= 0) {
		return;
	}
	int left = 0, right = size - 1;
	while (left < right) {
		while (left < right && !func(arr[left]) ) {
			left++;
		}
		while (left < right && func(arr[right])) {
			right--;
		}
		if (left < right) {
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
void reorderOddEven2(int* arr, int size) {
	reorder(arr, size, isEven);
}
void printArr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	reorderOddEven2(arr, 10);
	printArr(arr, 10);
	system("pause");
	return 0;
}