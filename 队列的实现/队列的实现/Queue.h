#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef int QDataType;
// 用带尾指针的单链表实现队列 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
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
// 初始化队列 
void QueueInit(Queue* q) {
	q->_front = q->_rear = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data) {
	QNode* newNode = createNode(data);
	if (q->_front == NULL) {
		q->_front = q->_rear = newNode;
	} else {
		q->_rear->_next = newNode;
		q->_rear = newNode;
	}
}
// 队头出队列 
void QueuePop(Queue* q) {
	//头删
	if (q->_front) {
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		//当队列中只有一个结点是，还需要将尾指针置为NULL
		if (next == NULL) {
			q->_rear = NULL;
		}
	}
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q) {
	if (q->_front == NULL) {
		return (QDataType)0;
	}
	return q->_front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q) {
	if (q->_rear == NULL) {
		return (QDataType)0;
	}
	return q->_rear->_data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q) {
	int n = 0;
	QNode* cur = q->_front;
	while (cur) {
		n++;
		cur = cur->_next;
	}
	return n;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q) {
	return q->_front == NULL;
}
// 销毁队列 
void QueueDestroy(Queue* q) {
	while (q->_front) {
		QNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
	}
	q->_front = q->_rear = NULL;
}