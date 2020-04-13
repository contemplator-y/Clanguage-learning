#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Number{
	char num[50]; //�������ֵ���ֵ����
	int size; // ���ֵ�ʵ��λ��
	int sign; //���ֵķ���
}Number;

//�������ַ���ת����Number���͵�����(�ַ����������ַ�����+����-��ͷ���ҳ���0�������������ֵ���ֵ���ֶ�����0��ͷ��
Number stringToNumber(char* s) {
	Number number = { 0 };
	int start = 0, len = strlen(s);
	//�������
	if (*s == '-') {
		number.sign = -1;
		start++;
	}
	else if (*s == '+') {
		number.sign = 1;
		start++;
	}
	else {
		number.sign = 1;
	}
	//������ֵ����(����������洢��
	for (int i = len - 1; i >= start; i--) {
		number.num[len - 1 - i] = *(s + i);
	}
	number.size = len - start;
	return number;
}

//��ӡ����
void printNumber(Number number) {
	if (number.sign == -1) {
		printf("%c",'-');
	}
	for (int i = number.size - 1; i >= 0; i--) {
		printf("%c", number.num[i]);
	}
	printf("\n");
}

//�Ƚ�����������ֵ���ֵĴ�С
int cmpNumber(Number number1, Number number2) {
	if (number1.size > number2.size) {
		return 1;
	}
	else if (number1.size < number2.size) {
		return -1;
	}
	//����λ����ȣ���λ�Ƚ�
	for (int i = number1.size - 1; i >= 0; i--) {
		if (number1.num[i] > number2.num[i]) {
			return 1;
		}
		else if (number1.num[i] < number2.num[i]) {
			return -1;
		}
	}
	return 0;
}
void numberSub(Number n1, Number n2, Number* res) {
	//��n1�е���ֵ���ּ�ȥn2�е���ֵ���ָ���res����ֵ����
	int i = 0;
	int borrow = 0;
	while (i < n2.size) {
		int tmp = 10 + n1.num[i]- n2.num[i] - borrow;
		res->num[i] = tmp % 10 + '0';
		borrow = 1 - tmp / 10;
		i++;
	}
	while (i < n1.size) {
		res->num[i] = n1.num[i];
		i++;
	}
	res->size = n1.size;
}

void numberAdd(Number n1, Number n2, Number* res) {
	//��n1��n2����ֵ������Ӹ���res ����ֵ����
	int i = 0;
	int carry = 0;
	while (i < n1.size || i < n2.size) {
		int tmp = carry;
		if (i < n1.size) {
			tmp = tmp + n1.num[i] - '0';
		}
		if (i < n2.size) {
			tmp = tmp + n2.num[i] - '0';
		}
		res->num[i++] = tmp % 10 + '0';
		carry = tmp / 10;
	}
	if (carry) {
		res->num[i++] = 1;
	}
	res->size = i;
}
Number highAdd(Number n1, Number n2) {
	Number res = { 0 };
	//����������ͬ
	if (n1.sign == n2.sign) {
		res.sign = n1.sign;
		//��ֵ�������
		numberAdd(n1, n2, &res);
	} else if (cmpNumber(n1, n2) == 1) {
		res.sign = n1.sign;
		numberSub(n1, n2, &res);
	} else if (cmpNumber(n1,n2) == 0) {
		res.sign = 1;
		res.num[0] = 0;
		res.size = 1;
	} else {
		res.sign = n2.sign;
		numberSub(n2, n1, &res);
	}
	return res;
}
int main() {
	char tmp[40] = { 0 };
	scanf("%s", tmp);
	Number n1 = stringToNumber(tmp);
	scanf("%s", tmp);
	Number n2 = stringToNumber(tmp);

	Number res = highAdd(n1, n2,&res);
	printNumber(res);
	system("pause");
	return 0;
}