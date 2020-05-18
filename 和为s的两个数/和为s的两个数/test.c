#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

//在排序数值中找两个之和等于tar的元素
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int * res = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;
	/*
	假设索引为a,b处的元素之和等于tar
	当left和right之和大于元素时，right一定大于b所以right--
	当两元素之和小于tar时，left一定小于a所以left++
	*/
	int left = 0, right = numsSize - 1;
	while (left < right) {
		int tmp = nums[left] + nums[right];
		if (tmp == target) {
			res[0] = nums[left];
			res[1] = nums[right];
			return res;
		}
		else if (tmp > target) {
			//左右处的元素之和大于tar，右边的索引向前移
			right--;
		}
		else {
			//两元素之和小于tar，左边的索引向后移
			left++;
		}
	}

	res[0] = res[1] = -1;
	return  res;
}
int main() {
	system("pause");
	return 0;
}