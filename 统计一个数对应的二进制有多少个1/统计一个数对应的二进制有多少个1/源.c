#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int countOne1(int n)
{
	int sum = 0;
	for (int i = n; i; i /= 2)
	{
		sum +=  i % 2;
	}
	return sum;
}

int countOne2(int n)
{
	int count = 0;
	while (n)
	{
		n &= n - 1;
		count++;
	}
	return count;
}

int countOne3(int n)
{
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff)+ ((n >> 16) & 0x0000ffff);

}
int main()
{
	printf("%d\n", countOne1(1023));
	printf("%d\n", countOne2(1023));
	printf("%d\n", countOne3(1023));

	system("pause");
	return 0;
}