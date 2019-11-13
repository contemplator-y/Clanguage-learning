#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：删除子串
**项目功能：给定一个子串，若已知字符串中含有该子串则将其删除，否则返回0
**完成时间：2019年11月11日
*/

int find_substr(char* str, char const * substr) {
	char* c = substr;
	int n = 0;
	while (*c != '\0' && *str != '\0') {
		if (*str == *c) {
			c++;
			n++;
			str++;
		}
		else {
			str++;
			n = 0;
			c = substr;
		}
	}
	if (*c == '\0') {
		return n;
	}
		
	return 0;
}
int de_substr(char* str, char const*substr) {
	int n = find_substr(str, substr);
	char* flag = str;
	if (n) {
		while (*substr != '\0') {
			if (*str == *substr) {
				flag = str;
				break;
			}
			str++;
		}

		while (1) {
			*flag = *(flag + n);
			if (*(flag + n) == '\0') {
				break;
			}
			flag++;
		}

		return 1;
	}
	return 0;
}

int main() {
	char a[] = "abcdefg";
	char b[] = "cd";
	int flag = de_substr(a, b);
	printf("%d\n", flag);
	printf("%s\n", a);

	system("pause");
	return 0;
}