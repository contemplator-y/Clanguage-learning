#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

int minArray(int* numbers, int numbersSize){
	for (int i = 0; i < numbersSize - 1; i++) {
		if (numbers[i] > numbers[i + 1])
			return numbers[i + 1];
	}
	return numbers[0];
}
int main() {
	system("pause");
	return 0;
}