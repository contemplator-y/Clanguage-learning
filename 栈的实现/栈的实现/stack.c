#include "Stack.h"


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
		ps->_a = (STDataType *)realloc(ps->_a, ps->_capacity * sizeof(STDataType);
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
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps) {
	return ps->_top;
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