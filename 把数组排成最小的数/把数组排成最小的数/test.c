#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//������ת�����ַ���
void itoa(int num, char* str) {
	if (num == 0) {
		str[0] = '0';
		str[1] = '\0';
		return;
	}
	//�õ����ֵ�λ��
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
//����ab��ba�Ĵ�Сȷ��ab����Ԫ���������е�˳��
int compare(const void* a, const void* b) {
	//�Ƚ��ַ���ab��ba�Ĵ�С������ab���ܻ������
	char* str1 = (char*)malloc(sizeof(char) * 21);
	char* str2 = (char*)malloc(sizeof(char) * 21);
	//�õ�ab
	itoa(*(int*)a, str1);
	itoa(*(int*)b, strlen(str1) + str1);
	//�õ�ba
	itoa(*(int*)b, str2);
	itoa(*(int*)a, strlen(str2) + str2);

	return strcmp(str1, str2);

}
char* minNumber(int* nums, int numsSize){
	if (numsSize == 0) {
		return NULL;
	}
	//�������������������
	qsort(nums, numsSize, sizeof(nums[0]), compare);
	char* res = (char*)malloc(sizeof(int) * 1001);
	res[0] = '\0';
	//����˳�������е�Ԫ��ת�����ַ�������res֮��
	for (int i = 0; i < numsSize; i++) {
		itoa(nums[i], res + strlen(res));
	}

	return res;
}

int main() {
	system("pause");
	return 0;
}