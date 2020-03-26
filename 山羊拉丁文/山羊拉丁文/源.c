#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void moveStr(char* str, int n, int start, int end) {
	while (start >= end) {
		*(str + start + n) = *(str + start);
		start--;
	}
}

void addA(char* str, int start, int n) {
	for (int i = 0; i < n; i++) {
		*(str + start) = 'a';
		start++;
	}
}
void leftRotate(char* str, int start, int end) {
	char tmp = *(str + start);
	for (int i = start; i < end; i++) {
		*(str + i) = *(str + i + 1);
	}
	*(str + end) = tmp;
}

char * toGoatLatin(char * S){
	int start = 0, end = 0;
	// 排除开始的空格
	while (*(S + start) == ' ') {
		start++;
	}
	char* res = S + start;
	int length = strlen(S);
	int n = 0, flag = 0;
	for (int i = start; i <= length; i++) {
		if (isalpha(*(S + i)) && (i == 0 || *(S + i - 1) == ' ')){
			if (*(S + i) == 'a' || *(S + i) == 'e' ||
				*(S + i) == 'i' || *(S + i) == 'o' || *(S + i) == 'u') {
				flag = 1;
			}
			start = i;
		}
		else if (isalpha(*(S + i - 1))) {
			end = i - 1;
			n++;
			if (flag == 0) {
				leftRotate(S, start, end);
			}
			moveStr(S, 2 + n, length, i);
			length += 2 + n;
			*(S + end + 1) = 'm';
			*(S + end + 2) = 'a';
			addA(S, end + 3, n);
			flag = 0;
			i += 2 + n;
		}
	}
	return res;
}
int main() {
	char S[1024] = "I speak Goat Latin";
	char* res = toGoatLatin(S);
	printf("%s\n", res);

	system("pause");
	return 0;
}