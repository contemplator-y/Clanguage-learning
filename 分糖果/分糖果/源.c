#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
��һЩ�ǹ��ָ��źöӵ�С���ѣ�����˳��֣���һ�θ���һ����һ�����ڶ��θ��ڶ��������������ε�����
�����һ�������Ժ���Ÿ���һ���֣�ÿһ�ηֵ��ǹ�������һ�ζ�1���������ʣ����ǹ���������ȫ����
��һ���ˡ���ÿ���˷ֵõ��ǹ�����
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