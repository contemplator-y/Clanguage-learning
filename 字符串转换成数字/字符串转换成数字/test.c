#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

int strToInt(char* str){
	//���ַ���
	if (str == NULL || *str == '\0')
		return 0;
	//����ǰ��Ŀհ��ַ�
	while (isspace(*str)) {
		str++;
	}
	//��һ���ǿ��ַ�����+-������
	if (*str != '+' && *str != '-' && !isdigit(*str))
		return 0;

	int sign = 1;
	if (!isdigit(*str)) {
		if (*str == '-')  {
			sign = -1;
		}
		str++;
	}
	//����ɨ������
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