#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	//�����ָ�����ָ�룬��ָ������k����Ȼ������ָ��һ���ߣ�����ָ���ߵ�NULL��ʱ��
	//��ָ�뼴�ߵ���n-k���ڵ㡣
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