#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

/*
�Ը�����һ��ֵxΪ��׼����������valС��x��ֵ�ƶ������ڵ���val�Ľ��֮ǰ���ұ��ֽ����Ⱥ�˳�򲻱䡣
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
	//�ҵ���һ��ֵС��x�Ľ����Ϊ�µ�ͷ���
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
	//start����ͷ���,��start��Ϊͷ
	if (start != pHead) {
		pre->next = start->next;
		start->next = pHead;
		pHead = start;
	}
	//������ֵС��x�Ľ��嵽start���棨start��һ��������x�Ļ���
	ListNode* cur = start->next;
	ListNode* pre2 = start;
	while (cur) {
		if (cur->val < x) {
			if (cur == start->next) {
				//����start
				pre2 = start = cur;
				cur = start->next;
			}
			else {
				//�嵽start����
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