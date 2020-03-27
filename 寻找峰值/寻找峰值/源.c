#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
��������������һ����ֵ���±꣬��ֵ��ָĳ��Ԫ�ر��������ߵ�Ԫ�ض��󣨶˵��Ԫ��ֻ����һ�߼��Ƿ�ֵ��
������������Ԫ�رز���ͬ��
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

	//���ֲ��ң���left��right�����Ƿ�ֵ��ʱ���ڣ�left��right����һ�����ڷ�ֵ��
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