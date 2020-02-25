#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void sort(int * a, int * b, int * c){
	if (*a > *b){
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
	if (*b > *c){
		int tmp = *b;
		*b = *c;
		*c = tmp;
	}
	if (*a > *b){
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}
int* numMovesStones(int a, int b, int c, int* returnSize){
	int * res = (int *)malloc(sizeof(int) * 2);
	sort(&a, &b, &c);
	int left = b - a - 1, right = c - b - 1;
	*(res + 1) = left + right;
	if (left == 0 && right == 0){
		*res = 0;
	}
	else if (left <= 1 || right <= 1){
		*res = 1;
	}
	else{
		*res = 2;
	}
	*returnSize = 2;
	return res;
}

int main(){
	int returnSize = 0;
	int * res = numMovesStones(4, 6, 8, &returnSize);
	printf("%d ", *res);
	printf("%d\n", *(res + 1));

	system("pause");
	return 0;
}