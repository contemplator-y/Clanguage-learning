#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse(char* start, char* end) {
	while (start < end) {
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}
char* reverseWords(char* s){
	if (s == NULL || *s == '\0') {
		return NULL;
	}
	//跳过前面的空格
	char* cur = s;
	while (*cur == ' ') {
		cur++;
	}
	if (*cur == '\0') {
		return NULL;
	}
	//开辅助空间
	int len = strlen(cur);
	char* res = (char*)malloc(sizeof(char) * len);
	int idx = 0;
	for (char* start = cur; start <= cur + len; start++) {
		//跳过多余的空格，拷贝字符到辅助空间
		if (*start != ' ' || *(start + 1) != ' ' && *(start + 1) != '\0') {
			res[idx++] = *start;
		}
	}

	reverse(res, res + idx - 2);
	//扫描剔除空格的字符串，翻转单词
	cur = res;
	char* start = cur;
	while (*cur) {
		if (*cur == ' ') {
			reverse(start, cur - 1);
			start = cur + 1;
		}
		cur++;
	}
	//翻转最后一个单词
	reverse(start, res + idx - 2);
	return res;
}
int main() {
	char str[] = "the sky is blue";
	char* res = reverseWords(str);
	printf("%s\n", res);
	system("pause");
	return 0;
}