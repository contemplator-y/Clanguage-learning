#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
ͳ��һ����1~2��,��n��¥�ݿ��ܵķ�����.
*/
int climbStairs(int n){
	if (n <= 2){
		return n;
	}
	int fir = 1, sec = 2, sum = 0;
	for (int tmp = 3; tmp <= n; tmp++){
		sum = fir + sec;
		fir = sec;
		sec = sum;
	}
	return sum;
}
int main(){
	printf("%d\n", climbStairs(3));
	system("pause");
	return 0;
}