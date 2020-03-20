#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Strncpy(char* dest, const char* src, size_t n) {
	for (size_t i = 0; i < n; i++) {
		*(dest + i) = *(src + i);
	}
	*(dest + n) = '\0';
	return dest;
}
int main() {
	char dest[] = "cai xu kun";
	char src[] = "qiao";
	char* res = Strncpy(dest, src, 3);
	printf("%s\n", res);
	system("pause");
	return 0;
}