#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ��ַ�ƥ��
**��Ŀ���ܣ������ַ���1��ƥ���ַ���2���κ��ַ��ĵ�һ���ַ�
**���ʱ�䣺2019��11��11��
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