#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
��һ��������ÿһλ��ƽ���ͣ�����ԭ����ֵ���ظ��������ֱ����������1��Ҳ����ʼ�ղ��ܵõ�1.
�����Ա��1����������ǿ�������
*/

#define true 1
#define false 0
int isHappy(int n){
	if (n == 1) {
		return true;
	}
	int t = 0;
	while (t < 10) {
		int tmp = 0;
		for (int i = n; i; i /= 10) {
			tmp += (i % 10) * (i % 10);
		}
		if (tmp == 1) {
			return true;
		}
		n = tmp;
		t++;
	}
	return false;
}
int main() {
	int res = isHappy(19);
	printf("%d\n", res);

	system("pause");
	return 0;
}