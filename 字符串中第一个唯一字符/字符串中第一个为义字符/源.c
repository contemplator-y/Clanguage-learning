#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
*/

int isExitCommonLetter(char* str, char tar, int* res) {
	int flag = 0, loc = -1;
	for (int i = 0; i < strlen(str); i++) {
		if (*(str + i) == tar && flag == 0) {
			flag++;
			loc = i;
		}
		else if (*(str + i) == tar) {
			flag++;
		}
	}
	if (flag == 1) {
		return loc;
	}
	return -1;
}
int firstUniqChar(char * s){
	int res = INT_MAX;
	for (char c = 'a'; c <= 'z'; c++) {
		int tmp = isExitCommonLetter(s, c, &res);
		if (tmp != -1 && tmp < res) {
			res = tmp;
		}
	}
	if (res == INT_MAX) {
		return -1;
	}
	return res;
}

int main() {
	char str[] = "ccaixukun";
	int tmp = firstUniqChar(str);
	printf("%d\n", tmp);
	system("pause");
	return 0;
}