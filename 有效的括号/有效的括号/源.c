#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

/*
�жϸ�����ֻ�������ŵ��ַ����е������Ƿ�ƥ��
*/
#define false 0
#define true 1

typedef int bool;
typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps) {
	ps->_capacity = 2;
	ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
	ps->_top = 0;
}
// ��ջ 
void StackPush(Stack* ps, STDataType data) {
	if (ps->_top == ps->_capacity) {
		ps->_capacity *= 2;
		ps->_a = (STDataType *)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
	}
	ps->_a[ps->_top++] = data;
}
// ��ջ 
void StackPop(Stack* ps) {
	if (ps->_top) {
		ps->_top--;
	}
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps) {
	if (ps->_top == 0) {
		return (STDataType)0;
	}
	return ps->_a[ps->_top - 1];
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps) {
	if (ps->_top == 0) {
		return 1;
	}
	return 0;
}
// ����ջ 
void StackDestroy(Stack* ps) {
	free(ps->_a);
	ps->_top = ps->_capacity = 0;
	ps->_a = NULL;
}
bool isValid(char * s){
	if (*s == '\0') {
		return true;
	}
	//��������ջ����������ջ��Ԫ�رȽ�
	Stack st;
	StackInit(&st);
	while (*s) {
		if (*s == '[' || *s == '(' || *s == '{') {
			StackPush(&st, *s);
			s++;
		}
		else {
			if (StackEmpty(&st)) {
				StackDestroy(&st);
				return false;
			}
			char tmp = StackTop(&st);
			if (*s == ')' && tmp + 1 != *s
				|| *s != ')' && tmp + 2 != *s) {
				StackDestroy(&st);
				return false;
			}
			StackPop(&st);
			s++;
		}
	}
	if (StackEmpty(&st) == 0) {
		StackDestroy(&st);
		return false;
	}
	return true;
}