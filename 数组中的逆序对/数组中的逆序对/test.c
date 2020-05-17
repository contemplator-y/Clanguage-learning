#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void merge(int* arr, int start, int mid, int end, int* tmp, int* res) {
	int start1 = start, end1 = mid, start2 = mid + 1, end2 = end;//从后往前开始归并
	int idx = end;
	while (end1 >= start1 && end2 >= start2) {
		if (arr[end1] > arr[end2]) {
			*res += end2 - start2 + 1;
			tmp[idx--] = arr[end1--];
		}
		else {
			tmp[idx--] = arr[end2--];
		}
	}
	//将剩余的元素拷贝至临时空间中
	if (end1 >= start1) {
		memcpy(tmp + start, arr + start1, sizeof(int) * (end1 - start1 + 1));
	}
	if (end2 >= start2) {
		memcpy(tmp + start, arr + start2 , sizeof(int) * (end2 - start2 + 1));
	}
	//将排好序的元素拷贝回原来的位置
	memcpy(arr + start, tmp + start, sizeof(int) * (end - start + 1));
}
void mergesort(int* arr, int n, int* tmp, int* res) {
	int k = 1; //待合并区间的长度
	while (k < n) {
		//一轮合并区间的过程
		for (int i = 0; i < n; i += 2 * k) {
			int start = i;
			int mid = i + k - 1;
			int end = i + 2 * k - 1;
			//mid是否越界
			if (mid >= n - 1) {
				continue;
			}
			//end是否越界
			if (end >= n) {
				end = n - 1;
			}
			merge(arr, start, mid, end, tmp, res);
		}
		k *= 2;
	}
}
int reversePairs(int* nums, int numsSize){
	if (numsSize <= 1) {
		return 0;
	}

	int res = 0;
	int* tmp = (int*)malloc(sizeof(int) * numsSize);
	mergesort(nums, numsSize, tmp, &res);
	return res;
}
int main() {
	int arr[] = { 7, 5, 6, 4, 2};
	int res = reversePairs(arr, 5);
	printf("%d\n", res);

	system("pause");
	return 0;
}