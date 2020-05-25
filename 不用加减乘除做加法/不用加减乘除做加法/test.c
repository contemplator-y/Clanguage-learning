#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

int add(int a, int b){
	//a + b �Ľ������ �����ǽ�λ��ӵĽ�� + ����λ���ɽ�λ������������һλ
	int sum, carry;
	do {
		sum = a ^ b;
		carry = (unsigned int)(a & b) << 1;
		a = sum;
		b = carry;
	} while (b);

	return sum;
}
int main() {
	int res = add(2, -1);
	printf("%d\n", res);

	system("pause");
	return 0;
}