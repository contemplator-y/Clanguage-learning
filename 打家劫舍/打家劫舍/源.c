#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int func(int* nums, int start, int end) {
	if (start == end - 1 || start == end) {
		return *(nums + start) > *(nums + end) ? *(nums + start) : *(nums + end);
	}
	int a = func(nums, start + 2, end) + *(nums + start);
	int b = func(nums, start + 1, end);
	return a > b ? a : b;
}

int findMax(int* nums, int size) {
	int max = 0, ord = 0;
	for (int i = 0; i < size; i++) {
		if (*(nums + i) > max) {
			max = *(nums + i);
			ord = i;
		}
	}
	return ord;
}
int rob(int* nums, int numsSize){
	if (numsSize == 0) {
		return 0;
	}
	int res = func(nums, 0, numsSize - 1);
	return res;

}

int main() {
	int nums[] = { 114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53,
		108};
	int res = rob(nums, 48);
	printf("%d\n", res);
	system("pause");
	return 0;
}