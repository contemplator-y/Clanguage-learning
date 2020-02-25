#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
统计一次爬1~2阶,爬n阶楼梯可能的方法数.
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