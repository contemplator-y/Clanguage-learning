#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ��ж��Ƿ�Ϊ�ȱ�������
**��Ŀ���ܣ�������������Ϊ�����εıߣ��ж��Ƿ񹹳������Σ���һ���ж��Ƿ�Ϊ�ȱ������λ����������
**���ʱ�䣺2019��11��4��
*/

int IS_Trian(int a,int b,int c) {
	if (a + b > c && a + c > b && b + c > a) {
		return 1;
	}
	return 0;
}

int ENOE(int a, int b, int c) {
	int n = 0;

	n = n + (a == b);
	n = n + (a == c);
	n = n + (b == c);

	return n;
}
int main() {
	int a, b, c, n;

	printf("�����������εı߳���\n");
	scanf("%d%d%d", &a, &b, &c);
	if (IS_Trian(a, b, c) == 1) {
		n = ENOE(a, b, c);
		switch (n) {
		case 0:
			printf("������Ϊ���ȱ�������\n");
			break;
		case 1:
			printf("������Ϊ����������\n");
			break;
		case 3:
			printf("������Ϊ�ȱ�������\n");
			break;
		}
	}
	else {
		printf("�������߲����������Σ�\n");
	}

	system("pause");
	return 0;
} 