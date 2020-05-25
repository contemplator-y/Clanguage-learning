#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

int add(int a, int b){
	//a + b 的结果等于 不考虑进位相加的结果 + 各个位置由进位产生的数左移一位
	int sum, carry;
	do {
		sum = a ^ b;
		carry = (unsigned int)(a & b) << 1;
		a = sum;
		b = carry;
	} while (b);

	return sum;
}
int main() {
	int res = add(2, -1);
	printf("%d\n", res);

	system("pause");
	return 0;
}