#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

//��������ֵ��������֮�͵���tar��Ԫ��
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int * res = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;
	/*
	��������Ϊa,b����Ԫ��֮�͵���tar
	��left��right֮�ʹ���Ԫ��ʱ��rightһ������b����right--
	����Ԫ��֮��С��tarʱ��leftһ��С��a����left++
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
			//���Ҵ���Ԫ��֮�ʹ���tar���ұߵ�������ǰ��
			right--;
		}
		else {
			//��Ԫ��֮��С��tar����ߵ����������
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