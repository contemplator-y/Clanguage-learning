#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int increment(char* s,int size) {
	int carry = 1;
	int res = 0;
	for (int i = size - 1; i >= 0; i--) {
		int sum = *(s + i) - '0' + carry;
		*(s + i) = sum % 10 + '0';
		carry = sum / 10;
	}
	if (carry == 1) {
		res = 1;
	}
	return res;
}

void printNum(char* s, int size) {
	int cur = 0;
	while (*(s + cur) == '0') {
		cur++;
	}
	while (*(s + cur)) {
		printf("%c", *(s + cur));
		cur++;
	}
	printf("\n");
}

void print1ToMaxOfNDigits(int n) {
	if (n <= 0) {
		return;
	}
	char* num = (char*)malloc(sizeof(char) * (n + 1));
	memset(num, '0', sizeof(char) * n);
	num[n] = '\0';
	while (!increment(num, n)) {
		printNum(num, n);
	}
}
int main() {
	int n = 0;
	scanf("%d", &n);
	print1ToMaxOfNDigits(n);
	system("pause");
	return 0;
}