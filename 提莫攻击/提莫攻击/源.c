#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
给定提莫攻击的时间序列,和每次攻击造成的中毒时间,求寒冰的总中毒时间.
*/
int findNext(int* arr, int start, int end, int tar) {
	while (start <= end) {
		if (arr[start] > tar) {
			return start;
		}
		start++;
	}
	return -1;
}
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
	if (timeSeriesSize <= 1) {
		return duration * timeSeriesSize;
	}
	int i = 0, d = 0;
	while (i < timeSeriesSize - 1) {
		int tmp = timeSeries[i] + duration;
		int k = findNext(timeSeries, i + 1, timeSeriesSize - 1, tmp);
		if (k == -1) {
			break;
		}
		if (timeSeries[k - 1] + duration < timeSeries[k]) {
			d += timeSeries[k] - timeSeries[k - 1] - duration;
		}
		i = k;

	}

	return timeSeries[timeSeriesSize - 1] + duration - timeSeries[0] - d;
}
int main() {
	int nums[] = { 3, 5, 6, 9, 12 }, r = 3;
	int tmp = findPoisonedDuration(nums, 5, 3);
	printf("%d\n", tmp);
	system("pause");
	return 0;
}