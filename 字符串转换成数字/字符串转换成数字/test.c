#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

int strToInt(char* str){
	//空字符串
	if (str == NULL || *str == '\0')
		return 0;
	//跳过前面的空白字符
	while (isspace(*str)) {
		str++;
	}
	//第一个非空字符不是+-和数字
	if (*str != '+' && *str != '-' && !isdigit(*str))
		return 0;

	int sign = 1;
	if (!isdigit(*str)) {
		if (*str == '-')  {
			sign = -1;
		}
		str++;
	}
	//遍历扫描数字
	long long num = 0;
	while (*str && isdigit(*str)) {
		num = num * 10 + *str - '0';
		if (sign == 1 && num > INT_MAX - 1) {
			return INT_MAX;
		}
		if (sign == -1 && num > INT_MAX) {
			return INT_MIN;
		}
		str++;
	}

	return sign * num;
}

int main() {
	system("pause");
	return 0;
}