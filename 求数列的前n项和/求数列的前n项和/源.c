#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ����:������ǰn���
**��Ŀ����:��1/1-1/2+1/3-1/4...+1/99-1/100
**���ʱ��2019��11��6��
*/

double Sum(int n) {  
	double sum = 0.0;
	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0) {
			sum = sum - 1.0 / (double)i;
		} 
		else {
			sum = sum + 1.0 / (double)i;
		  }
	}
	return sum;
}

int main() {
	printf("sum = %f\n", Sum(100)); 

	system("pause");
	return 0;
}  