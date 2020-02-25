#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

char *  strConnect(char * dst,   char * src)
{
	char * tmp;
	for (tmp = dst; *tmp; tmp++);
	for (char * m = src; *m; m++)
	{
		*tmp = *m;
		tmp++;
	}
	*tmp = '\0';
	return dst;
}
int main()
{
	char dst[20]= "caixukun";
	char src[] = "qiaobiluo";
	char * tmp = strConnect(dst, src);
	printf("%s\n",tmp);

	system("pause");
	return 0;
}