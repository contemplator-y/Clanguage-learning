#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
�ҵ�������ֻ����һ�ε�����,�������־���������
*/
int singleNumber(int* nums, int numsSize){
	int res = *nums;
	for (int i = 1; i < numsSize; i++){
		res = ~res ^*(nums + i);
	}
	return res;
}

int main(){
	int nums[] = { 2, 3, 4, 4, 3 };
	int tmp = singleNumber(nums, 5);
	printf("%d\n", tmp);
	system("pause");
	return 0;
}