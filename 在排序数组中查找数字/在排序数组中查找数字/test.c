#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

//统计数字在排序数组中出现在次数

//在排序数组中找tar的开始索引
int getFirst(int* arr, int start, int end, int tar) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == tar) {
			if (mid == 0 || arr[mid - 1] != tar) {
				return mid;
			}
			end = mid - 1;
		}
		else if (arr[mid] > tar) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return -1;
}
//在数组中找tar的结束索引
int getRear(int* arr, int n, int tar) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == tar) {
			if (mid == n - 1 || arr[mid + 1] != tar) {
				return mid;
			}
			start = mid + 1;
		}
		else if (arr[mid] > tar) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return -1;
}
int search(int* nums, int numsSize, int target){
	if (numsSize == 0) {
		return 0;
	}
	//用二分法分别找tar在数组中的开始和结束索引
	int first = getFirst(nums, 0, numsSize - 1, target);
	if (first == -1) {
		return 0;
	}
	int rear = getRear(nums, numsSize, target);
	return rear - first + 1;
}
int main() {
	system("pause");
	return 0;
}