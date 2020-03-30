#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。
*/

void reverse(int* arr, int left, int right) {
	while (left < right) {
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
int* addToArrayForm(int* A, int ASize, int k, int* returnSize){
	//获取结果数组的长度
	int n = 0;
	int tmp = k;
	while (tmp) {
		tmp /= 10;
		n++;
	}
	//开空间
	int resArrLen = n > ASize ? n + 1 : ASize + 1;
	int* res = (int*)malloc(sizeof(int) * resArrLen);

	//模拟加法
	int carry = 0;
	int idx = ASize - 1;
	int i = 0;
	while (idx >= 0 || k > 0) {
		res[i] = carry;
		if (idx >= 0) {
			res[i] += A[idx];
			idx--;
		}
		if (k > 0) {
			res[i] += k % 10;
			k /= 10;
		}
		if (res[i] > 9) {
			res[i] -= 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		i++;
	}
	//判断最高位是否存在进位
	if (carry) {
		res[i++] = 1;
	}
	reverse(res, 0, i - 1);
	*returnSize = i;
	return res;
}

int main() {
	int nums[] = { 1, 2, 0, 0 };
	int k = 34;
	int size = 0;
	int* res = addToArrayForm(nums, 4, k,&size);
	for (int i = 0; i < size; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}