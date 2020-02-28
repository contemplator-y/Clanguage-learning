#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0
void rotate(char *s, int size){
	char tmp = *s;
	for (int i = 0; i < size - 1; i++){
		*(s + i) = *(s + i + 1);
	}
	*(s + size - 1) = tmp;
}

int rotateString(char * A, char * B){
	if (strlen(A) == 0 || strlen(B) == 0){
		return false;
	}
	if (strcmp(A, B) == 0){
		return true;
	}
	int size = strlen(B);
	for (int i = 0; i < size - 1; i++){
		rotate(B, size);
		if (strcmp(A, B) == 0){
			return true;
		}
	}
	return false;
}

int main(){
	char a[] = "abcde", b[] = "cdeab";
	printf("%d\n", rotateString(a, b));
	system("pause");
	return 0;
}