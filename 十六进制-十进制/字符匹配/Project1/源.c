#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：字符匹配
**项目功能：查找字符串1中匹配字符串2中任何字符的第一个字符
**完成时间：2019年11月11日
*/

char* find_char(char const * source, char const *chars) {
	char* c = chars;
	while (*source != '\0') {
		while (*c != '\0') {
			if (*source == *c) {
				return source;
			}
			else {
				c++;
			}
		}
		source++;
		c = chars;
	}
	return NULL;
}
int main() {
	char a[] = "abcdef";
	char b[] = "gbijf";
	char* c = find_char(a, b);
	printf("%c", *c);
	system("pause");
	return 0;
}