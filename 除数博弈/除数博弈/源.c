#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1
/*
两个人轮流玩游戏。给定一个初始的整数N，轮到游戏的人可以找到一个N的除数x，且x小于N
并将N改成N-x。知道某个人无法进行这种操作则游戏结束。判断对于给定的N先手是否必胜。
*/

int divisorGame(int N){
	if (N == 1) {
		return false;
	}
	int* flag = malloc(sizeof(int) * N);//对应位置为1表示先手必胜，为-1表示先手必败
	*flag = -1;
	for (int i = 2; i <= N; i++) {
		int j = 1;
		for (; j <= i / 2; j++) {
			if (i % j == 0 && *(flag + i - j - 1) == -1) {
				*(flag + i - 1) = 1;
				break;
			}
		}
		if (j == i / 2 + 1) {
			*(flag + i - 1) = -1;
		}
	}
	return *(flag + N - 1);
}
int main() {
	int res = divisorGame(32);
	printf("%d\n", res);

	system("pause");
	return 0;
}