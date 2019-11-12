#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**项目名称：折半查找
**项目功能：在有序整型数组中用折半查找法查找指定元素，找到返回下标，否则返回-1.
**完成时间：2019年11月12日
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