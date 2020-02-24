#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>

/*
函数f用于统计字符串中最小字母出现的次数
给两个字符串数组q和w，返回和第一个数组长度一样的整数数组
内容为q中相应位置的f返回值小于w中f返回值的数目
*/

int f(char * s){
	int num = 0;
	char tar = *s;
	for (; *s; s++){
		if (*s < tar){
			tar = *s;
			num = 1;
		}
		else if (*s == tar){
			num++;
		}
	}
	return num;
}
int* numSmallerByFrequency(char ** queries, int queriesSize, 
	char ** words, int wordsSize, int* returnSize){
	int * tmp = (int *)malloc(sizeof(int) * queriesSize);
	int * m = (int *)malloc(sizeof(int) * wordsSize);
	for (int j = 0; j < wordsSize; j++){
		*(m + j) = f(*(words + j));
	}
	for (int i = 0; i < queriesSize; i++){
		*(tmp + i) = 0;
		int q = f(*(queries + i));
		for (int j = 0; j < wordsSize; j++){
			if (q < *(m + j)){
				*(tmp + i) += 1;
			}
		}
	}
	*returnSize = queriesSize;
	return tmp;
}
int main(){
	char *q[] = { "cbd" }, *w[] = { "zaaaz" };
	int returnsize = 0;
	int* tmp = numSmallerByFrequency(q, 1, w, 1, &returnsize);
	for (int i = 0; i < returnsize; i++){
		printf("%d ", *(tmp + i));
	}
	printf("\n");
	system("pause");
	return 0;
}