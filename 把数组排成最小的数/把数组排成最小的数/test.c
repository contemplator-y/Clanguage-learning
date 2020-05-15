#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//将数字转换成字符串
void itoa(int num, char* str) {
	if (num == 0) {
		str[0] = '0';
		str[1] = '\0';
		return;
	}
	//得到数字的位数
	int size = 0;
	for (int i = num; i; i /= 10) {
		size++;
	}
	int idx = size - 1;
	for (int i = num; i; i /= 10) {
		str[idx--] = i % 10 + '0';
	}
	str[size] = '\0';
}
//根据ab和ba的大小确定ab两个元素在数组中的顺序
int compare(const void* a, const void* b) {
	//比较字符串ab和ba的大小（数字ab可能会溢出）
	char* str1 = (char*)malloc(sizeof(char) * 21);
	char* str2 = (char*)malloc(sizeof(char) * 21);
	//得到ab
	itoa(*(int*)a, str1);
	itoa(*(int*)b, strlen(str1) + str1);
	//得到ba
	itoa(*(int*)b, str2);
	itoa(*(int*)a, strlen(str2) + str2);

	return strcmp(str1, str2);

}
char* minNumber(int* nums, int numsSize){
	if (numsSize == 0) {
		return NULL;
	}
	//根据排序规则将数组排序
	qsort(nums, numsSize, sizeof(nums[0]), compare);
	char* res = (char*)malloc(sizeof(int) * 1001);
	res[0] = '\0';
	//按照顺序将数组中的元素转换成字符串连在res之后
	for (int i = 0; i < numsSize; i++) {
		itoa(nums[i], res + strlen(res));
	}

	return res;
}

int main() {
	system("pause");
	return 0;
}