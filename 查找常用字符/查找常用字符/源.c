#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
给定仅有小写字母构成的字符串数组，返回在每个字符串中都出现的字符
（包含重复的字符）
*/
int findLetter(char* str, char tar) {
	int n = 0;
	for (; *str; str++) {
		if (*str == tar) {
			n++;
		}
	}
	return n;
}
char ** commonChars(char ** A, int ASize, int* returnSize){
	char** res = malloc(sizeof(char*) * strlen(*A));
	int ord = 0;
	for (char tar = 'a'; tar <= 'z'; tar++) {
		int tmp = findLetter(*A, tar);
		if (tmp == 0) {
			continue;
		}
		for (int j = 1; j < ASize; j++) {
			int t = findLetter(*(A + j), tar);
			if (t == 0) {
				tmp = 0;
				break;
			}
			else if (t < tmp) {
				tmp = t;
			}
		}
		if (tmp != 0) {
			for (int k = 0; k < tmp; k++) {
				*(res + ord) = malloc(sizeof(char) * 2);
				res[ord][0] = tar;
				res[ord][1] = '\0';
				ord++;
			}
		}
	}
	*returnSize = ord;
	return res;
}
int main() {
	char* str[] = { "bella", "label", "roller" };
	int returnSize = 0;
	char** tmp = commonChars(str, 3, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%s ", tmp[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}