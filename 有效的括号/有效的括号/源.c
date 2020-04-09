#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

/*
判断给定的只包含括号的字符串中的括号是否匹配
*/
#define false 0
#define true 1

typedef int bool;
typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;
// 初始化栈 
void StackInit(Stack* ps) {
	ps->_capacity = 2;
	ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
	ps->_top = 0;
}
// 入栈 
void StackPush(Stack* ps, STDataType data) {
	if (ps->_top == ps->_capacity) {
		ps->_capacity *= 2;
		ps->_a = (STDataType *)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
	}
	ps->_a[ps->_top++] = data;
}
// 出栈 
void StackPop(Stack* ps) {
	if (ps->_top) {
		ps->_top--;
	}
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps) {
	if (ps->_top == 0) {
		return (STDataType)0;
	}
	return ps->_a[ps->_top - 1];
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps) {
	if (ps->_top == 0) {
		return 1;
	}
	return 0;
}
// 销毁栈 
void StackDestroy(Stack* ps) {
	free(ps->_a);
	ps->_top = ps->_capacity = 0;
	ps->_a = NULL;
}
bool isValid(char * s){
	if (*s == '\0') {
		return true;
	}
	//左括号入栈，右括号与栈顶元素比较
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