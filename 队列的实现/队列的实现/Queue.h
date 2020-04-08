#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef int QDataType;
// �ô�βָ��ĵ�����ʵ�ֶ��� 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

QNode* createNode(QDataType x) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}
// ��ʼ������ 
void QueueInit(Queue* q) {
	q->_front = q->_rear = NULL;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data) {
	QNode* newNode = createNode(data);
	if (q->_front == NULL) {
		q->_front = q->_rear = newNode;
	} else {
		q->_rear->_next = newNode;
		q->_rear = newNode;
	}
}
// ��ͷ������ 
void QueuePop(Queue* q) {
	//ͷɾ
	if (q->_front) {
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		//��������ֻ��һ������ǣ�����Ҫ��βָ����ΪNULL
		if (next == NULL) {
			q->_rear = NULL;
		}
	}
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q) {
	if (q->_front == NULL) {
		return (QDataType)0;
	}
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q) {
	if (q->_rear == NULL) {
		return (QDataType)0;
	}
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q) {
	int n = 0;
	QNode* cur = q->_front;
	while (cur) {
		n++;
		cur = cur->_next;
	}
	return n;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q) {
	return q->_front == NULL;
}
// ���ٶ��� 
void QueueDestroy(Queue* q) {
	while (q->_front) {
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
	}
	q->_front = q->_rear = NULL;
}