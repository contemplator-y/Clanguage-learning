#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

/*
以给定的一个值x为基准，将链表中val小于x的值移动到大于等于val的结点之前，且保持结点的先后顺序不变。
*/

typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;

typedef struct singleList {
	ListNode* head;
}single;
void singleListInit(single* sl) {
	sl->head = NULL;
}
void singleListPushFront(single* sl,int x) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->val = x;
	node->next = sl->head;
	sl->head = node;
}
void singleListPrint(ListNode* start) {
	while (start) {
		printf("%d->", start->val);
		start = start->next;
	}
	printf("NULL\n");
}
ListNode* partition(ListNode* pHead, int x) {
	if (pHead == NULL) {
		return NULL;
	}
	if (pHead->next == NULL) {
		return pHead;
	}
	//找到第一个值小于x的结点作为新的头结点
	ListNode* start = pHead, *pre = NULL;
	while (start) {
		if (start->val < x) {
			break;
		}
		pre = start;
		start = start->next;
	}
	if (start == NULL) {
		return pHead;
	}
	//start不是头结点,将start作为头
	if (start != pHead) {
		pre->next = start->next;
		start->next = pHead;
		pHead = start;
	}
	//将后面值小于x的结点插到start后面（start下一个结点大于x的话）
	ListNode* cur = start->next;
	ListNode* pre2 = start;
	while (cur) {
		if (cur->val < x) {
			if (cur == start->next) {
				//更新start
				pre2 = start = cur;
				cur = start->next;
			}
			else {
				//插到start后面
				pre2->next = cur->next;
				cur->next = start->next;
				start->next = cur;
				start = cur;
				cur = pre2->next;
			}
		}
		else {
			pre2 = cur;
			cur = cur->next;
		}

	}
	return pHead;
}

int main() {
	single sl;
	singleListInit(&sl);
	singleListPushFront(&sl, 1);
	singleListPushFront(&sl, 2);
	singleListPushFront(&sl, 3);
	singleListPushFront(&sl, 4);
	singleListPushFront(&sl, 5);
	singleListPrint(sl.head);
	ListNode* res = partition(sl.head, 3);
	singleListPrint(res);

	system("pause");
	return 0;
}