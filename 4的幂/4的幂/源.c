#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
�ж�һ�������Ƿ���4���ݴη�
*/
#define true 1
#define false 0

int  isPowerOfFour(int num){
	if (num <= 0) {
		return false;
	}
	// //�з������ͷ�Χ��4������ݴη�Ϊ15
	// return   (int)pow(4,15) % num == 0;

	//32λ����������1,3,5..λ����һ��Ϊ1������λΪ0 ��ʱ������4����
	int tmp = 1;
	int flag = 0;
	for (int i = 0; i < 31; i++) {
		if (num & (tmp << i)) {
			if (i % 2) {
				return false;
			}
			if (flag == 0) {
				flag = 1;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int res = isPowerOfFour(16);
	printf("%d\n", res);
	system("pause");
	return 0;
}