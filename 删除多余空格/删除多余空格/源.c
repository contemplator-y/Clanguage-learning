#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
**��Ŀ���ƣ�ɾ������ո�
**��Ŀ���ܣ�ɾ������Ŀո�ֻ���������ո��е�һ��
**���ʱ�䣺2019��11��8��
*/

char * deblank(char a[], int size) {
	char b[50];
	int num = 0, i = 0;
	for (int j = 0; j < size; j++) {
		if (a[j] != ' ') {
			if (j == 0) {
				b[i] = a[j];
				i += 1;
			}
			else if(num > 0){
				b[i] = ' ';
				b[i + 1] = a[j];
				i += 2;
				num = 0;
			}
				else {
					b[i] = a[j];
					i += 1;
				}
		}
		else {
			num = num + 1;
		}
	}
	strcpy(a, b);
	return a;
}
int main() {
	char a[] = "abc       defghi         y";//���ַ���������������ո�����strlen�����ַ�������
															//�����ʱ��ֻ��һ��
	char* c = deblank(a, 50);
	printf("ɾ���ո����ַ���Ϊ��%s\n%d", a,strlen(a));

	system("pause");
	return 0;
}