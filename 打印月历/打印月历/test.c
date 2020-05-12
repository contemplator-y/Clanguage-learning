#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//����1�����ܼ��͵��µ�������ӡ���·ݵ�����
void print(int start, int days) {
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	int n = 0;//��¼��ӡ�ĸ���
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
//�ж��Ƿ�Ϊ����
int isLeapYear(int year) {
	if (year % 400 == 0) {
		return 1;
	}
	if (year % 4 == 0 && year % 100 != 0) {
		return 1;
	}
	return 0;
}
//��1970��1��1�����ļ��㵱ǰ�·�1�����ܼ�
int getDayOfWeek(int year, int mon) {
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int dayOfWeek = 4;
	//����year��1��1���ܼ�
	for (int y = 1971; y <= year; y++) {
		//ƽ������һ�գ�������������
		dayOfWeek = (dayOfWeek + 1 + isLeapYear(y - 1)) % 7;
	}
	days[1] += isLeapYear(year);
	//���㵱ǰ�·�1�����ܼ�
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
		printf("��������ݺ��·ݣ�\n");
		scanf("%d %d", &year, &mon);
		//�����ݺ��·��Ƿ���Ч
		if (checkOk(year, mon)) {
			days[1] += isLeapYear(year); //������,1��ʾ���꣬0��ʾƽ��
			break;
		}
		printf("������������\n");
	}
	int dayOfWeek = getDayOfWeek(year, mon);
	//����1�����ܼ��͵��µ�������ӡ����
	print(dayOfWeek, days[mon - 1]);
}
int main() {
	printCalendar();
	system("pause");
	return 0;
}