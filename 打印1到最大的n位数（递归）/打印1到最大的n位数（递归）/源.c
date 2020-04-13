#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

/*
递归实现打印从1到最大的n位数
*/

void printNumber(char* number,int len) {
	int cur = 0;
	//跳过数字前面的0
	while (*(number + cur) == '0') {
		cur++;
	}
	while (*(number + cur)) {
		printf("%c", *(number + cur));

		cur++;
	}
	printf("\n");
}
void getNextNumber(char* number, int len, int idx) {
	if (idx == len) {
		printNumber(number,len);
		return;
	}
	for (int i = 0; i < 10; i++) {
		number[idx] = i + '0';
		getNextNumber(number, len, idx + 1);
	}
}
void print1ToMaxOfNDigits(int n) {
	if (n <= 0) {
		return;
	}
	char* number = (char*)malloc(sizeof(char) * (n + 1));
	number[n] = '\0';
	getNextNumber(number, n, 0);
	free(number);
}
int main() {
	print1ToMaxOfNDigits(-2);
	system("pause");
	return 0;
}