#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
��������������ȵ�����A��B,A�����B�����ƿ�����,����A[i]>B[i[������i����Ŀ������.
����A����������,ʹ�������B���������
*/
int findMax(int * arr, int size){
	int m = 0, ord = 0;
	for (int i = 0; i < size; i++){
		if (*(arr + i) >= m){
			m = *(arr + i);
			ord = i;
		}
	}
	return ord;
}
int findMin(int * arr, int size){
	int n = (int)pow(10, 9), ord = 0;
	for (int i = 0; i < size; i++){
		if (*(arr + i) < n && *(arr + i) >= 0){
			n = *(arr + i);
			ord = i;
		}
	}
	return ord;
}
int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize){
	int * tmp = (int *)malloc(sizeof(int) * ASize);
	for (int i = 0; i < ASize; i++){
		int start = findMax(A, ASize), end = findMin(A, ASize);
		int ord = findMax(B, BSize);
		if (*(A + start) > *(B + ord)){
			*(tmp + ord) = *(A + start);
			*(A + start) = -1;
		}
		else{
			*(tmp + ord) = *(A + end);
			*(A + end) = -1;
		}
		*(B + ord) = -1;
	}
	*returnSize = ASize;
	return tmp;
}
int main(){
	int A[] = { 2, 7, 11, 15 }, B[] = { 1, 10, 4, 11 };
	int returnSize = 0;
	int * tmp = advantageCount(A, 4, B, 4, &returnSize);
	for (int i = 0; i < returnSize; i++){
		printf("%d ", *(tmp + i));
	}

	printf("\n");
	system("pause");
	return 0;
}