#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
��һ���ַ���ת����ʮ������������+��-��������Ϊ��ʼ���������ַ�������
��Ϊ�մ����߲���ת���������򷵻�0.
*/
int Atoi(const char* str) {
	if (strlen(str) == 0) {
		return 0;
	}
	int num = 0, sign = 1;
	for (; *str; str++) {
		if (*str == '+') {
			str++;
			break;
		}
		if (*str == '-') {
			sign = -1;
			str++;
			break;
		}
		if (*str >= '0' && *str <= '9') {
			num = *str - '0';
			str++;
			break;
		}
	}
	for (; *str; str++) {
		if (*str >= '0' && *str <= '9') {
			if (num * sign == INT_MAX / 10 && *str - '0' > INT_MAX % 10
				|| num * sign> INT_MAX / 10
				|| num * sign< INT_MIN / 10 ||
				num * sign == INT_MIN / 10 && *str - '0' > -(INT_MIN % 10)) {
				return 0;
			} 
			num = num * 10 + *str - '0';
			continue;
		}
		break;
	}
	return num * sign;
}
int main() {
	char str[] = "vasjgajs+21474.83647*";
	int res = Atoi(str);
	printf("%d\n", res);

	system("pause");
	return 0;
}