#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
���1-n������n�������з����У���������������λ�õ����з����ĸ���������1e9+7ȡģ��
*/
	
#define MAX (int)(1e9 + 7)
long long fac(int n) {
	if (n <= 2) {
		return n;
	}
	long long res = n;
	while (n > 1) {
		res = res * (n - 1) % MAX;
		n--;
	}
	return res;
}
int isPrime(int n) {
	for (int i = 2; i <= (int)sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}
int CountPrimes(int n) {
	int s = 0;
	for (int i = 2; i <= n; i++) {
		int tmp = isPrime(i);
		if (tmp == 1) {
			s++;
		}
	}
	return s;
}
int numPrimeArrangements(int n){
	if (n <= 2) {
		return 1;
	}
	int sum = CountPrimes(n);
	long long res = (fac(sum)  * fac(n - sum)) % MAX;
	return (int)res;
}

int main() {
	int res = numPrimeArrangements(5);
	printf("%d\n", res);
	system("pause");
	return 0;
}