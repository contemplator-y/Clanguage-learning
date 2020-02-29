#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int(*func)(int, int);
int bigger(int a, int b) {
	return a > b ? 1 : 0;
}

int smaller(int a, int b) {
	return a < b ? 1 : 0;
}
void bubbleSort(int* arr, int size,func f) {
	for (int bound = 0; bound < size - 1; bound++) {
		for (int start = size - 1; start > bound; start--) {
			if (f(arr[start - 1] ,arr[start]) == 0) {
				int tmp = arr[start];
				arr[start] = arr[start - 1];
				arr[start - 1] = tmp;
			}
		}
	}
}
int main() {
	int arr[] = { 9, 5, 2, 7 };
	bubbleSort(arr, 4,bigger);
	for (int i = 0; i < 4; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubbleSort(arr, 4, smaller);
	for (int i = 0; i < 4; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}