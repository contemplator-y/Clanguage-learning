#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
��дһ�������ҳ�������ֻ����һ�ε����֡�
*/

int* findsingleNum(int* arr, int size) {
	int* res = (int*)malloc(sizeof(int) * 2);
	int ord = 0;
	for (int i = 0; i < size ; i++) {
		int tar = *(arr + i), s = 0;
		for (int j = 0; j < size; j++) {
			if (arr[j] == tar) {
				s++;
			}
		}
		if (s == 1) {
			*(res + ord) = tar;
			ord++;
		}
	}
	return res;
}
int main() {
	int arr[] = { 3, 5, 6, 6, 1, 3, 5, 8,8,24 };
	int* res = findsingleNum(arr, 10);
	printf("%d %d\n", *res, *(res + 1));
	free(res);
	system("pause");
	return 0;
}