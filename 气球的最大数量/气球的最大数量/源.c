#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
ʹ�ø����ַ����е��ַ������ɵ���balloon��ÿ����ĸ���ֻ�ܱ�ʹ��һ�Ρ����ܹ�ƴ�ճ���balloon���ʵĸ���
*/

int maxNumberOfBalloons(char * text){
	int tmp[5] = { 0 };
	for (; *text; text++) {
		if (*text == 'b') {
			tmp[0] += 2;
		}
		else if (*text == 'a') {
			tmp[1] += 2;
		}
		else if (*text == 'l') {
			tmp[2]++;
		}
		else if (*text == 'o') {
			tmp[3]++;
		}
		else if (*text == 'n') {
			tmp[4] += 2;
		}
	}
	int m = INT_MAX;
	for (int i = 0; i < 5; i++) {
		if (*(tmp + i) < m) {
			m = *(tmp + i);
		}
	}
	return m / 2;
}
int main() {
	char str[] = "loonbalxballpoon";
	int tmp = maxNumberOfBalloons(str);
	printf("%d\n", tmp);

	system("pause");
	return 0;
}