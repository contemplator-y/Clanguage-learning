#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int dayOfYear(char * date){
	int year = 0;
	for (int i = 0; i <= 3; i++) {
		year = 10 * year + *(date + i) - '0';
	}
	int flag = 0;//ÈòÄê±ê¼Ç
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
		flag = 1;
	}
	int mon = 10 * (*(date + 5) - '0') + *(date + 6) - '0';
	int day = 10 * (*(date + 8) - '0') + *(date + 9) - '0';
	if (mon < 1 || mon > 12 || day < 1 || day > 31
		|| day > 28 + flag && mon == 2 ||
		(mon == 4 || mon == 9 || mon == 11 || mon == 6) && day > 30) {
		return -1;
	}
	int days[] = { 31, 28 + flag, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	for (int i = 0; i < mon - 1; i++) {
		sum += days[i];
	}
	return sum + day;
}
int main() {
	char day[] = "2004-03-01";
	int res = dayOfYear(day);
	printf("%d\n", res);

	system("pause");
	return 0;
}