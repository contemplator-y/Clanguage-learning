#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>



 struct ListNode {
     int val;
    struct ListNode *next;
};

void rotateOne(struct ListNode* head) {
	struct ListNode* pre = NULL;
	struct ListNode* last = head;
	while (last->next) {
		pre = last;
		last = last->next;
	}
	if (pre) {
		pre->next = NULL;
		last->next = head;
		head = last;
	}
}

struct ListNode* rotateRight(struct ListNode* head, int k){
	int n = 0;
	rotateOne(head);
	return head;
}
int main() {
	system("pause");
	return 0;
}