#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//a��0����1���
int muiti(int a, int b) {
	if (b == 1) {
		return a;
	}
	return 0;
}

//����A * B
int multiply(int A, int B){
	//ģ����ʽ�˷�
	int sum = 0;
	for (int i = 0; i < 32; i++) {
		int b = B >> i;
		int tmp = muiti(A, b % 2);
		sum += tmp << i;
	}

	return sum;
}
int main() {
	system("pause");
	return 0;
}