#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

/*
�������������е����Ϊ�����ĺ����Ϊż���ķֱ�����һ��
*/
struct ListNode* oddEvenList(struct ListNode* head){
	if (head == NULL || head->next == NULL) {
		return head;
	}
	//��ԭ������������ź�ż����Ź��ɵ�����Ȼ��ż�����ӵ���������ȥ
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