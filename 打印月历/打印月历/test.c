#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//根据1号是周几和当月的天数打印该月份的日历
void print(int start, int days) {
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	int n = 0;//记录打印的个数
	for (int i = 0; i < start; i++) {
		printf("    ");
		n++;
	}
	for (int i = 1; i <= days; i++) {
		printf("%-4d", i);
		n++;
		if (n % 7 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}
//判断是否为闰年
int isLeapYear(int year) {
	if (year % 400 == 0) {
		return 1;
	}
	if (year % 4 == 0 && year % 100 != 0) {
		return 1;
	}
	return 0;
}
//以1970年1月1日周四计算当前月份1号是周几
int getDayOfWeek(int year, int mon) {
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int dayOfWeek = 4;
	//计算year年1月1日周几
	for (int y = 1971; y <= year; y++) {
		//平年往后一日，闰年往后两日
		dayOfWeek = (dayOfWeek + 1 + isLeapYear(y - 1)) % 7;
	}
	days[1] += isLeapYear(year);
	//计算当前月份1号是周几
	for (int i = 0; i < mon - 1; i++) {
		dayOfWeek = (dayOfWeek + days[i]) % 7;
	}

	return dayOfWeek;
}

int checkOk(int year, int mon) {
	if (year < 1970 || year > 3000 || mon < 1 || mon > 12) {
		return 0;
	}
	return 1;
}
void printCalendar() {
	int year = 0, mon = 0;
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (1) {
		printf("请输入年份和月份：\n");
		scanf("%d %d", &year, &mon);
		//检查年份和月份是否有效
		if (checkOk(year, mon)) {
			days[1] += isLeapYear(year); //闰年标记,1表示闰年，0表示平年
			break;
		}
		printf("您的输入有误！\n");
	}
	int dayOfWeek = getDayOfWeek(year, mon);
	//根据1号是周几和当月的天数打印月历
	print(dayOfWeek, days[mon - 1]);
}
int main() {
	printCalendar();
	system("pause");
	return 0;
}