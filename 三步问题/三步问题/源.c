#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
上n阶楼梯，每次可以上1或者2或者3步，统计所有的上法
*/

#define MAX 1000000007
int waysToStep(int n){
	if (n == 1 || n == 2) {
		return n;
	}
	if (n == 3) {
		return 4;
	}
	int a = 1, b = 2, c = 4, res = 0;
	for (int i = 4; i <= n; i++) {
		res = ((a % MAX + b % MAX) % MAX + c % MAX) % MAX;
		a = b;
		b = c;
		c = res;
	}
	return res;
}

int main() {
	int res = waysToStep(32);
	printf("%d\n", res);

	system("pause");
	return 0;
}