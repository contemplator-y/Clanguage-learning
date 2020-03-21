#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
将一些糖果分给排好队的小朋友，按照顺序分，第一次给第一个分一个，第二次给第二个分两个，依次递增，
给最后一个分完以后接着给第一个分，每一次分的糖果数比上一次多1，如果少于剩余的糖果数，则将其全部给
下一个人。求每个人分得的糖果数。
*/
int* distributeCandies(int candies, int num_people, int* returnSize){
	int* res = (int*)calloc(num_people, sizeof(int));
	*returnSize = num_people;
	int n = 1;
	while (candies != 0) {
		int tmp = n % num_people, ord = 0;
		if (tmp == 0) {
			ord = num_people - 1;
		}
		else {
			ord = tmp - 1;
		}
		if (n <= candies) {
			*(res + ord) += n;
			candies -= n;
			n++;
		}
		else {
			*(res + ord) += candies;
			candies = 0;
		}
	}
	return res;
}
int main() {
	int returnSize = 0;
	int* res = distributeCandies(10, 3, &returnSize);
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", *(res + i));
	}
	free(res);
	system("pause");
	return 0;
}