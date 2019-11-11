#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

extern int negate(int a);
extern int increment(int a);
int main() {
	printf("%d\n", increment(10));
	printf("%d\n", negate(10));
	printf("%d\n", increment(0));
	printf("%d\n", negate(0));
	printf("%d\n", increment(-10));
	printf("%d\n", negate(-10));

	system("pause");
	return 0;
}