#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
/*
����һ��ֻ����'A','L','P'�����ַ����ַ���������ַ����в�����һ����A',�Ҳ���������'L'���򷵻�1,���򷵻�0.
*/

#define true 1
#define false 0

int checkRecord(char * s){
	int Anums = 0;
	int Pnums = 0;
	while (*s && Anums <= 1 && Pnums <= 2) {
		if (*s == 'A') {
			Anums++;
			Pnums = 0;
		}
		else if (*s == 'L') {
			Pnums++;
		}
		else {
			Pnums = 0;
		}
		s++;
	}
	if (Anums > 1 || Pnums > 2) {
		return false;
	}
	return true;
}
int main() {
	int res = checkRecord("PPALLP");
	printf("%d\n", res);
	system("pause");
	return 0;
}