#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ�����ʽ����Ǻ�
**���ʱ�䣺2019��11��9��
*/

void Star(int n) {
	for (int i = 0; i < n; i++) {
		printf("%c", '*');
	}
	printf("\n");
}//��ӡһ��n���Ǻ�

void Print_star(int max) {
	for (int i = 1; i < 2 * max; i++) {
		if (i % 2 == 0) {
			printf("\n");
		}
		else if (i <= max) {
				Star(i);
		}
			else {
				Star(2 * max - i);
		}
	}
}//maxΪһ���Ǻŵ����ֵ��ÿ�����Ǻż��һ��

int main() {
	Print_star(13);

	system("pause");
	return 0;
}