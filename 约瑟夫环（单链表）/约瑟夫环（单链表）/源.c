#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
**n个人围坐一圈，1-3报数，报到3的人退出，求最后一个人。
*/

#define len sizeof(M)
#define N 7

typedef struct Man
{
	int num;
	struct Man * next;
}M;

M* create()
{
	M * head = (M*)malloc(len);
	head->num = 1;
	M * p = head;
	int n = N - 1;
	while (n)
	{
		p->next= (M*)malloc(len);
		p->next->num = N - n + 1;
		p = p->next;
		n--;
	}
	p->next = head;
	return head;
}

void delete(M * p)
{
	M * tmp = p->next;
	p->next = p->next->next;
	free(tmp);
}

void game(M * p)
{
	if (p->next->next == p)
	{
		printf("%d %d\n", p->num, p->next->num);
		return;
	}
	delete(p->next);
	game(p->next->next);
}
int main()
{
	M * head = create();
	game(head);
	system("pause");
	return 0;
}