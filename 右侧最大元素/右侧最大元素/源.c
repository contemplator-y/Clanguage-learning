#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
将数组的每一个元素都改为右侧的最大元素，从首元素开始，最后一个改为-1.
*/

int findMax(int* arr, int size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}
int* replaceElements(int* arr, int arrSize, int* returnSize){
	int* res = (int*)malloc(sizeof(int) * arrSize);
	*returnSize = arrSize;
	for (int i = 0; i < arrSize - 1; i++) {
		int max = findMax(arr + i + 1, arrSize - i - 1);
		res[i] = max;
	}
	res[arrSize - 1] = -1;
	return res;
}
int main() {
	int arr[] = { 17, 18, 5, 4, 6, 1 };
	int returnSize = 0;
	int* res = replaceElements(arr, 6, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", *(res + i));
	}

	system("pause");
	return 0;
}