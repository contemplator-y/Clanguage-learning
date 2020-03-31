#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	//定义快指针和慢指针，快指针先走k步，然后两个指针一起走，当快指针走到NULL的时候
	//慢指针即走到底n-k个节点。
	ListNode* fast, *slow;
	fast = slow = pListHead;
	while (k && fast) {
		k--;
		fast = fast->next;
	}
	if (k) {
		return NULL;
	}
	while (fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main() {
	system("pause");
	return 0;
}