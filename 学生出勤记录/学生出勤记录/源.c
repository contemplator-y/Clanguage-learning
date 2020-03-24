#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
/*
给定一个只包含'A','L','P'三个字符的字符串，如果字符串中不超过一个’A',且不超过两个'L'，则返回1,否则返回0.
*/

#define true 1
#define false 0

int checkRecord(char * s){
	int Anums = 0;
	int Pnums = 0;
	while (*s && Anums <= 1 && Pnums <= 2) {
		if (*s == 'A') {
			Anums++;
			Pnums = 0;
		}
		else if (*s == 'L') {
			Pnums++;
		}
		else {
			Pnums = 0;
		}
		s++;
	}
	if (Anums > 1 || Pnums > 2) {
		return false;
	}
	return true;
}
int main() {
	int res = checkRecord("PPALLP");
	printf("%d\n", res);
	system("pause");
	return 0;
}