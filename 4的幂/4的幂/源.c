#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
判断一个整数是否是4的幂次方
*/
#define true 1
#define false 0

int  isPowerOfFour(int num){
	if (num <= 0) {
		return false;
	}
	// //有符号整型范围内4的最大幂次方为15
	// return   (int)pow(4,15) % num == 0;

	//32位整数仅仅在1,3,5..位上有一个为1，其他位为0 的时候它是4的幂
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