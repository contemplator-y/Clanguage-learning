#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

/*
�ж�һ�������Ƿ��ǻ��ĵ�
*/

#define true 1
#define false 0
typedef int bool;

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

void singleListPushFront(single* sl, int x) {
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

ListNode* reverseList(ListNode* start) {
	if (start == NULL || start->next == NULL) {
		return start;
	}
	//��start����һ����㿪ʼͨ��ͷ�巴ת
	ListNode* cur = start->next, *pre = start;
	while (cur) {
		ListNode* next = cur->next;
		pre->next = next;
		cur->next = start;
		start = cur;
		cur = next;
	}
	return start;
}

bool chkPalindrome(ListNode* A) {
	if (A == NULL || A->next == NULL) {
		return true;
	}
	//��ȡ�м���֮��һ������λ��
	ListNode* slow, *fast;
	slow = fast = A;
	while (fast) {
		fast = fast->next;
		if (fast) {
			fast = fast->next;
		}
		slow = slow->next;
	}
	//��ת��벿��֮����ǰ�벿��һһ�Ƚ�
	ListNode* p1 = A, *p2 = reverseList(slow);
	while (p2) {
		if (p1->val != p2->val) {
			return false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	reverseList(slow);
	return true;
}
int main() {
	single sl;
	singleListInit(&sl);
	singleListPushFront(&sl, 1);
	singleListPushFront(&sl, 2);
	singleListPushFront(&sl, 3);
	singleListPushFront(&sl, 2);
	singleListPushFront(&sl, 1);

	singleListPrint(sl.head);
	bool res = chkPalindrome(sl.head);
	printf("%d\n", res);

	system("pause");
	return 0;
}