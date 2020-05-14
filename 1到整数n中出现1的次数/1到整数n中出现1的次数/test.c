#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//获取数字n的位数以及最高位的数字
void getHignDigitAndPlace(int n, int* HighNum, int* place) {
	*place = 0;
	for (; n; n /= 10) {
		(*place)++;
		if (n < 10) {
			*HighNum = n;
		}
	}
}

int countDigitOne(int n){
	if (n < 10) {
		return 1;
	}
	int HighNum = 0, place = 0; //数字n的位数和最高位的数字
	//获取到位数和最高位的数字
	getHignDigitAndPlace(n, &HighNum, &place);
	if (HighNum == 1) {
		//最高位数字为1
		int tmp = (int)pow(10, place - 1);
		return  countDigitOne(tmp - 1)
			+ (n - tmp + 1) + countDigitOne(n - tmp);
	} else {
		//最高位不是1
		int tmp = (int)pow(10, place - 1);
		return HighNum * countDigitOne(tmp - 1)
			+ tmp + countDigitOne(n - tmp * HighNum);
	}
}

int main() {
	int n = 12;
	int res = countDigitOne(n);
	printf("%d\n", res);

	system("pause");
	return 0;
}