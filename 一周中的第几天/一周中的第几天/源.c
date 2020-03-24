#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
输入一个1971年1月1日以后的一个有效日期，计算当天是周几。
*/

// 计算当前日期距离1971年1月1日有多少天。1970年1月1日是星期四
//365 = 7 * 52 + 1

int monthDay[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int CountNum(int day, int month, int year) {
	int d = 0;
	for (int y = 1971; y <= year; y++) {
		d++;
		if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0) {
			d++;
		}
	}
	if ((year % 400 == 0 || year % 4 == 0 && year % 100 != 0) && month < 3) {
		d--;
	}
	int sum = 0;
	for (int m = 0; m < month - 1; m++) {
		sum += monthDay[m];
	}
	sum += day;
	d += sum % 7;
	d = (d + 3) % 7;
	return d;

}
char * dayOfTheWeek(int day, int month, int year){
	char* days[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	int d = CountNum(day, month, year);
	if (d == 0) {
		return days[6];
	}
	return days[d - 1];
}
int main(){
	char* res = dayOfTheWeek(31, 8, 2019);
	printf("%s\n", res);

	system("pause");
	return 0;
}