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

ListNode* deleteDuplication(ListNode* pHead) {
	//����ǰ������һ�����ȣ�ɾ���¸����֮������жϣ�ֱ���¸���㲻��ȣ�Ȼ��ɾ����ǰ��㡣
	if (pHead == NULL || pHead->next == NULL) {
		return pHead;
	}
	ListNode* pre = NULL, *cur = pHead, *next = pHead->next;
	while (next) {
		if (next->val == cur->val) {
			while (next->val == cur->val) {
				//ɾ��next���
				cur->next = next->next;
				free(next);
				next = cur->next;
				if (next == NULL) {
					break;
				}
			}
			//ɾ����ǰ���
			if (pre == NULL) {
				//��ǰ���Ϊͷ���
				pHead = next;
			}
			else {
				//��ǰ��㲻��ͷ���
				pre->next = next;
			}
			free(cur);
			cur = next;
			if (cur != NULL) {
				next = cur->next;
			}
		}
		else {
			pre = cur;
			cur = next;
			next = cur->next;
		}
	}
	return pHead;
}
int main() {
	single sl;
	singleListInit(&sl);
	singleListPushFront(&sl, 5);
	singleListPushFront(&sl, 4);
	singleListPushFront(&sl, 4);
	singleListPushFront(&sl, 3);
	singleListPushFront(&sl, 3);
	singleListPushFront(&sl, 2);
	singleListPushFront(&sl, 1);

	singleListPrint(sl.head);
	ListNode* res = deleteDuplication(sl.head);
	singleListPrint(res);

	system("pause");
	return 0;
}