#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ���ȡ�����ַ�
**��Ŀ���ܣ����ж�ȡ�����У����ÿ������ĳ��ȣ�Ȼ�����������С�
**���ʱ�䣺2019��11��4��
*/

int main() {
	char a[100];
	int b[10] = { 0 }, i = 0, n = 0;

	//��ȡ���룬�ԡ�����Ϊ������־
	while (1) {
		a[i] = getchar();
		n += 1;
		if (a[i] == '!') {
			break;
		}
		i += 1;
	}

	//����ÿ���ַ��ĸ���
	int m = 0;
	for (int j = 0; j < n - 1; j++) {
		if (a[j] == '\n') {
			m += 1;
		}
		else {
			b[m] += 1;
		}
	}

	//�������
	int max = 0;
	for (int i = 0; i < 10; i++) {
		if (b[i] > b[max]) {
			max = i;
		}
	}
	int s = 0;
	for (int i = 0; i < max; i++) {
		s = s + b[i];
	}

	for (int i = s; i < s + b[max] + 1; i++) {
		printf("%c", a[i]);
	}

	system("pause");
	return 0;
}