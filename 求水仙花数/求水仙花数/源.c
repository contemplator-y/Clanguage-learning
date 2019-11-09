#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
**项目名称：求水仙花数
**项目功能：求出0～999之间的所有“水仙花数”并输出。 
**完成时间：2019年11月9日
*/

void Narnum() {
	int a, b, c;
	for (int i = 0; i < 1000; i++) {
		a = i / 100;
		b = (i - a * 100) / 10;
		c = i - 100 * a - 10 * b;
		if (pow(a,3) + pow(b,3)+ pow(c,3) == i) {
			printf("%d ", i);
		}
	}
}
int main() {
	Narnum();
	system("pause");
	return 0;
}