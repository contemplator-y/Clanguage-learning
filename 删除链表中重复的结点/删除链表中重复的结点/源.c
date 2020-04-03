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
	//若当前结点和下一结点相等，删除下个结点之后继续判断，直到下个结点不相等，然后删除当前结点。
	if (pHead == NULL || pHead->next == NULL) {
		return pHead;
	}
	ListNode* pre = NULL, *cur = pHead, *next = pHead->next;
	while (next) {
		if (next->val == cur->val) {
			while (next->val == cur->val) {
				//删除next结点
				cur->next = next->next;
				free(next);
				next = cur->next;
				if (next == NULL) {
					break;
				}
			}
			//删除当前结点
			if (pre == NULL) {
				//当前结点为头结点
				pHead = next;
			}
			else {
				//当前结点不是头结点
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