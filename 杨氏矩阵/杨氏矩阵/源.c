#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
在每行,每列递增的矩阵中查找目标元素是否存在
*/
int findNum(int nums[3][3], int tar){
	if (tar < nums[0][0]){
		return 0;
	}
	int i, flag = 1;
	for ( i = 0; i < 3 && flag; i++) {
		if (tar == nums[i][i]) {
			return 1;
		}
		else if (tar < nums[i][i]) {
			for (int j = 0; j < i; j++) {
				if (nums[i][j] == tar || nums[j][i] == tar) {
					return 1;
				}
				else if (nums[i][j] > tar || nums[j][i] > tar) {
					flag = 0;
				}
			}
		}
	}
	return 0;
}
int main() {
	int nums[3][3] = {
			{1,2,3},
			{2,4,5},
			{3,5,7}
	};
	printf("%d\n", findNum(nums, 1));

	system("pause");
	return 0;
}