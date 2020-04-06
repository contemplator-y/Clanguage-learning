#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

/*
将单链表中所有的序号为奇数的和序号为偶数的分别连在一起
*/
struct ListNode* oddEvenList(struct ListNode* head){
	if (head == NULL || head->next == NULL) {
		return head;
	}
	//将原链表拆成奇数序号和偶数序号构成的链，然后将偶数链接到奇数链上去
	struct ListNode* headOdd = head->next, *cur = headOdd->next;
	struct ListNode* pre1 = head, *pre2 = headOdd;
	int i = 0;
	while (cur) {
		if (i % 2 == 0) {
			pre1->next = cur;
			pre1 = cur;
		}
		else {
			pre2->next = cur;
			pre2 = cur;
		}
		i++;
		cur = cur->next;
	}
	pre2->next = NULL;
	pre1->next = headOdd;
	return head;
}

int main() {
	system("pause");
	return 0;
}