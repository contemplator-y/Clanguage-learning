#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ���ƣ��۰����
**��Ŀ���ܣ��������������������۰���ҷ�����ָ��Ԫ�أ��ҵ������±꣬���򷵻�-1.
**���ʱ�䣺2019��11��12��
*/

int Binarysearch(int arr[], int size, int tar)
{
	int left = 0;
	int right = size - 1;
	int mid = 0;
	while (left <= right)
	{
		mid = (right + left) / 2;
		if (arr[mid] > tar)
		{
			right = mid - 1;
		}
		else if (arr[mid] < tar)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int tmp = Binarysearch(arr, 7, 2);
	printf("%d\n", tmp);
	
	system("pause");
	return 0;
}