#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define Tar 9
#define Max 100

/*
**��Ŀ����:ͳ��9�ĸ���
**��Ŀ����:ͳ��1-100������9���ֵĴ���
**���ʱ��:2019��11��6��
*/

int Count(int m ,int n) {
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		if (i / 10 == n) {
			sum++;
		}
		if(i % 10 == n) {
			sum++;
		}
	}
	return sum;
}

int main() {
	printf("%d����%d�ĸ���Ϊ:%d\n", Max, Tar,Count(Max,Tar));

	system("pause");
	return 0;
}