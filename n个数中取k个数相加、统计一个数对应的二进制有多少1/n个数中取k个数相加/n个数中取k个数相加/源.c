#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**��Ŀ����:����һ��nԪ������,��ӡ��������ȡk������͵����н��(ÿһ����һ��Ԫ�ز����ظ�ȡ)
**���ʱ��:2019��11��24��
*/

//�õݹ�ģ�����ѭ��
void printNum(int * src,int n,int k,int start,int ans)
{
	if (k <= 0) //ѡ��k��Ԫ�غ��ӡ
	{
		printf("%d\n", ans);
		return;
	}
	for (int i = start; i < n; i++) // ���ѭ���൱�ڴ�n��Ԫ����ѡ��һ��Ԫ�صĹ���,��ͨ�õĹ���
	{								//ѭ������������ظ�ѡȡ�Ĺ���k��
		printNum(src, n, k - 1, i + 1,ans + src[i]);
	}
}

//for (int i = 0; i < n; i++)
//{
//	for (int j = j + 1; j < n; j++)
//	{
//		for (int k = j + 1; k < n; k++)
//		{
//			printf("%d\n", *(src + i) + *(src + j) + *(src + k));
//		}
//	}
//}
int main()
{
	int src[20] = { 0 };
	int n = 0;
	scanf("%d", &n);
	int k = 0;
	scanf("%d", &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", src + i);
	}
	printNum(src, n, k, 0, 0);

	system("pause");
	return 0;
}