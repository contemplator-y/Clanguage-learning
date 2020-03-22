#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
�������������� x �� y�����ĳһ�������� x^i + y^j���������� i >= 0 �� j >= 0����ô������Ϊ��������һ��ǿ������
��С�ڵ���bound�ڵ�����ǿ������
*/

int findNum(int*arr, int size, int tar) {
	for (int i = 0; i < size; i++) {
		if (*(arr + i) == tar) {
			return 1;
		}
	}
	return 0;
}
int* powerfulIntegers(int x, int y, int bound, int* returnSize){
	if (bound <= 1) {
		*returnSize = 0;
		return NULL;
	}
	int * res = (int*)malloc(sizeof(int) * bound);
	int s = 0, num1 = 0;
	for (int i = 1; i < bound && num1 <= 19; i *= x) {
		num1++;
		int num2 = 0;
		for (int j = 1; j < bound && num2 <= 19; j *= y) {
			num2++;
			if (i + j <= bound && findNum(res, s, i + j) == 0) {
				*(res + s) = i + j;
				s++;
			}
		}
	}
	*returnSize = s;
	return res;
}
int main() {
	int returnsize = 0;
	int* res = powerfulIntegers(2, 3, 10, &returnsize);
	for (int i = 0; i < returnsize; i++) {
		printf("%d ", *(res + i));
	}
	free(res);
	system("pause");
	return 0;
}