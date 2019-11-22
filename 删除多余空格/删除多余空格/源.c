#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
**项目名称：删除多余空格
**项目功能：删除多余的空格，只保留连续空格中的一个
**完成时间：2019年11月8日
*/

char * deblank(char a[], int size) {
	char b[50];
	int num = 0, i = 0;
	for (int j = 0; j < size; j++) {
		if (a[j] != ' ') {
			if (j == 0) {
				b[i] = a[j];
				i += 1;
			}
			else if(num > 0){
				b[i] = ' ';
				b[i + 1] = a[j];
				i += 2;
				num = 0;
			}
				else {
					b[i] = a[j];
					i += 1;
				}
		}
		else {
			num = num + 1;
		}
	}
	strcpy(a, b);
	return a;
}
int main() {
	char a[] = "abc       defghi         y";//在字符数组中连续多个空格在用strlen计算字符串长度
															//和输出时都只记一个
	char* c = deblank(a, 50);
	printf("删除空格后的字符串为：%s\n%d", a,strlen(a));

	system("pause");
	return 0;
}