#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int fib(int n){
	if (n < 2) {
		return n;
	}
	int fir = 0, sec = 1, thi = 0;
	for (int i = 2; i <= n; i++) {
		thi = (fir + sec) % (int)(1e9 + 7);
		fir = sec;
		sec = thi;
	}
	return thi;
}

int main() {
	printf("%d\n", fib(30));
	system("pause");
	return 0;
}