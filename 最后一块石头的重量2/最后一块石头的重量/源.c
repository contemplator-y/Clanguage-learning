#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
每次石头中重量第二大的击碎,若第一大和第二大的重量一样,则击碎最大的两块,否则将最大的
重量修改为两者之差,求剩下最后一块石头的重量,没有石头剩下就返回0
*/
void findBig(int * arr, int size, int * fir, int *sec){
	int m = 0, n = 0, f = 0, s = 0;
	for (int i = 0; i < size; i++){
		if (*(arr + i) > m){
			n = m;
			m = *(arr + i);
			s = f;
			f = i;
		}
		else if (*(arr + i) > n){
			n = *(arr + i);
			s = i;
		}
	}
	*fir = f;
	*sec = s;
}

int lastStoneWeight(int* stones, int stonesSize){
	int fir = 0, sec = 0, s = stonesSize;
	while (s > 1){
		findBig(stones, stonesSize, &fir, &sec);
		if (*(stones + fir) == *(stones + sec)){
			s -= 2;
		}
		else{
			s -= 1;
		}
		*(stones + fir) = *(stones + fir) - *(stones + sec);
		*(stones + sec) = 0;

	}
	if (s == 1){
		for (int i = 0; i < stonesSize; i++){
			if (*(stones + i)){
				return *(stones + i);
			}
		}
	}
	return 0;
}
int main(){
	int arr[] = { 2, 7, 4, 1, 8, 1 };
	int tmp = lastStoneWeight(arr, 6);
	printf("%d\n", tmp);

	system("pause");
	return 0;
}