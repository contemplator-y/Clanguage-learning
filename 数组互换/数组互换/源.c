#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

/*
**��Ŀ����:���黥��
**��Ŀ����:�������������е�����
**���ʱ��:2019��11��5��
*/

void Exchange(int a[], int b[]) {
	int c = 0;
	for (int i = 0; i < SIZE; i++) {
		c = a[i];
		a[i] = b[i];
		b[i] = c;
	}
}

int main() {
	int a[SIZE], b[SIZE];

	printf("������������(ÿ��5��)��\n");
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &b[i]);
	}

	Exchange(a, b);

	printf("������Ľ��Ϊ��\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", b[i]);
	}
	
	system("pause");
	return 0;
}