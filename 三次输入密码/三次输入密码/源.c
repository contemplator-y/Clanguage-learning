#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
**��Ŀ���ƣ�������������
**��Ŀ���ܣ��������벢��֤���ɹ���ʾ��½�ɹ���������ʾ�������룬����������Ρ�
**���ʱ�䣺2019��11��12��
*/

int main()
{
	char pass[] = "888888";
	char s[6];
	int n = 0;
	do
	{
		if (n == 3)
		{
			printf("����������Σ�\n");
			break;
		}

		printf("���������룺");
		scanf("%s", &s);
		if (strcmp(s, pass) == 0)
		{
			printf("��½�ɹ���\n");
			break;
		}
		
		else
		{
			printf("�������!\n");
			n++;
		}
	} while (1);

	system("pause");
	return 0;
}