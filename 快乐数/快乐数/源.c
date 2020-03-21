#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
求一个正整数每一位的平方和，代替原来的值。重复这个过程直到这个数变成1，也可能始终不能得到1.
若可以变成1，这个数就是快乐数。
*/

#define true 1
#define false 0
int isHappy(int n){
	if (n == 1) {
		return true;
	}
	int t = 0;
	while (t < 10) {
		int tmp = 0;
		for (int i = n; i; i /= 10) {
			tmp += (i % 10) * (i % 10);
		}
		if (tmp == 1) {
			return true;
		}
		n = tmp;
		t++;
	}
	return false;
}
int main() {
	int res = isHappy(19);
	printf("%d\n", res);

	system("pause");
	return 0;
}