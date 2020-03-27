#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
返回数组中任意一个峰值的下标，峰值是指某个元素比左右两边的元素都大（端点的元素只满足一边即是峰值）
且数组中相邻元素必不相同。
*/

int findPeakElement(int* nums, int numsSize){
	if (numsSize <= 1) {
		return 0;
	}
	if (nums[0] > nums[1]) {
		return 0;
	}
	if (nums[numsSize - 1] > nums[numsSize - 2]) {
		return numsSize - 1;
	}

	//二分查找（当left和right都不是峰值的时候，在（left，right）中一定存在峰值）
	int left = 0, right = numsSize - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (mid == 0) {
			return 1;
		}
		if (nums[mid - 1] > nums[mid]) {
			right = mid - 1;
		}
		else if (nums[mid + 1] < nums[mid]) {
			return mid;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}
int main() {
	int nums[] = { 1, 2, 3, 1 };
	int idx = findPeakElement(nums, 4);
	printf("%d\n", idx);

	system("pause");
	return 0;
}