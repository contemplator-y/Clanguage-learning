#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
求一个数组中三个数相乘的最大结果
*/
int maximumProduct(int* nums, int numsSize){
	//找数组中最大的三个数，最小的两个数
	int maxFir = -1001, maxSec = -1001, maxThir = -1001, minFir = 1001, minSec = 1001;
	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > maxFir) {
			maxThir = maxSec;
			maxSec = maxFir;
			maxFir = nums[i];
		}
		else if (nums[i] > maxSec) {
			maxThir = maxSec;
			maxSec = nums[i];
		}
		else if (nums[i] > maxThir) {
			maxThir = nums[i];
		}

		if (nums[i] < minFir) {
			minSec = minFir;
			minFir = nums[i];
		}
		else if (nums[i] < minSec) {
			minSec = nums[i];
		}
	}
	int a = maxSec * maxThir;
	int b = minSec * minFir;
	if (a > b) {
		return a * maxFir;
	}
	return b * maxFir;

}
int main() {
	int nums[] = { -4, -3, -2, -1, 60 };
	int res = maximumProduct(nums, 5);
	printf("%d\n", res);
	system("pause");
	return 0;
}