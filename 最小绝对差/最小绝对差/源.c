#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
给一个整数数组 arr，其中每个元素都不相同。
找到所有具有最小绝对差的元素对，并且按升序的顺序返回。
*/

int cmp_int(const void* _a, const void* _b) {
	int* a = (int*)_a;
	int* b = (int*)_b;
	return *a - *b;
}
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
	int min = INT_MAX;
	qsort(arr, arrSize, sizeof(arr[0]), cmp_int);
	for (int i = 0; i < arrSize - 1; i++) {
		if (arr[i + 1] - arr[i] < min) {
			min = arr[i + 1] - arr[i];
		}
	}
	int** res = malloc(sizeof(int*) * (arrSize - 1));
	int ord = 0;
	for (int i = 0; i < arrSize - 1; i++) {
		if (arr[i + 1] - arr[i] == min) {
			*(res + ord) = malloc(sizeof(int) * 2);
			res[ord][0] = arr[i];
			res[ord][1] = arr[i + 1];
			ord++;
		}

	}
	int* tmp = malloc(sizeof(int) * ord);
	for (int i = 0; i < ord; i++) {
		tmp[i] = 2;
	}
	*returnColumnSizes = tmp;
	*returnSize = ord;
	return res;
}

int main() {
	int arr[] = { 4, 2, 1, 3 };
	int returnSize = 0;
	int* returnColumnSizes = 0;
	int** res = minimumAbsDifference(arr, 4, &returnSize, &returnColumnSizes);
	for (int i = 0; i < returnSize; i++) {
		for (int j = 0; j < *returnColumnSizes; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	system("pause");
	return 0;
}