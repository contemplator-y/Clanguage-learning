#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int findContinueNum(char * start)
{
	int count = 0;
	while (isdigit(*start))
	{
		count++;
		start++;
	}
	return count;
}

int charsToNum(char * start, int n)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp = *(start + i) - '0';
		num += tmp * (int)pow(10, n - i - 1);
	}
	return num;
}
void printArr(int * arr, int n)
{
	if (n < 0)
	{
		return;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}
int main()
{
	char str[100];
	scanf("%[^\n]", str);
	int arr[100] = { 0 };
	int n = 0;
	for (char * start = str; *start;)
	{
		int count = findContinueNum(start);
		if (count)
		{
			arr[n] = charsToNum(start, count);
			start += count;
			n++;
			continue;
		}
		start++;
	}
	printf("%d\n", n);
	printArr(arr, n);

	system("pause");
	return 0;
}