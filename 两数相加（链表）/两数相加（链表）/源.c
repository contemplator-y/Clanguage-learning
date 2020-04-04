#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
给出两个非空链表表示两个非负整数。
它们的位数是从低位开始存储的，且每一个结点只存储了一位数。
返回一个新的链表表示两个数相加的和（也是从低位开始存储）。
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	struct ListNode* p1 = l1, *p2 = l2;
	struct ListNode* head, *pre;
	head = pre = NULL;

	//模拟加法的竖式运算
	int carry = 0;
	while (p1 || p2) {
		int tmp = carry;
		if (p1) {
			tmp += p1->val;
			p1 = p1->next;
		}
		if (p2) {
			tmp += p2->val;
			p2 = p2->next;
		}
		struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
		node->val = tmp % 10;
		node->next = NULL;
		if (pre == NULL) {
			pre = head = node;
		}
		else {
			pre->next = node;
			pre = node;
		}
		carry = tmp / 10;
	}
	if (carry) {
		struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
		node->val = 1;
		node->next = NULL;
		pre->next = node;
		pre = node;
	}
	return head;
}

int main() {
	system("pause");
	return 0;
}