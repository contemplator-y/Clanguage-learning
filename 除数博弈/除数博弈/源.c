#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
/*
��������������Ϸ������һ����ʼ������N���ֵ���Ϸ���˿����ҵ�һ��N�ĳ���x����xС��N
����N�ĳ�N-x��֪��ĳ�����޷��������ֲ�������Ϸ�������ж϶��ڸ�����N�����Ƿ��ʤ��
*/

int divisorGame(int N){
	if (N == 1) {
		return false;
	}
	int* flag = malloc(sizeof(int) * N);//��Ӧλ��Ϊ1��ʾ���ֱ�ʤ��Ϊ-1��ʾ���ֱذ�
	*flag = -1;
	for (int i = 2; i <= N; i++) {
		int j = 1;
		for (; j <= i / 2; j++) {
			if (i % j == 0 && *(flag + i - j - 1) == -1) {
				*(flag + i - 1) = 1;
				break;
			}
		}
		if (j == i / 2 + 1) {
			*(flag + i - 1) = -1;
		}
	}
	return *(flag + N - 1);
}
int main() {
	int res = divisorGame(32);
	printf("%d\n", res);

	system("pause");
	return 0;
}