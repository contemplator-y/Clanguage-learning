#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：读取多行字符
**项目功能：逐行读取输入行，算出每行输入的长度，然后输出最长的那行。
**完成时间：2019年11月4日
*/

int main() {
	char a[100];
	int b[10] = { 0 }, i = 0, n = 0;

	//读取输入，以‘！’为结束标志
	while (1) {
		a[i] = getchar();
		n += 1;
		if (a[i] == '!') {
			break;
		}
		i += 1;
	}

	//计算每行字符的个数
	int m = 0;
	for (int j = 0; j < n - 1; j++) {
		if (a[j] == '\n') {
			m += 1;
		}
		else {
			b[m] += 1;
		}
	}

	//找最大行
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