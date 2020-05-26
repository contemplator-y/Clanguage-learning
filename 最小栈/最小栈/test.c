#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* arr1;
	int* arr2; //用另一个栈来保存入栈过程中出现的最小值，栈顶元素为当前栈中的最小值
	int size1;
	int size2;
	int capacity1;
	int capacity2;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack* mst = (MinStack*)malloc(sizeof(MinStack));
	mst->size1 = mst->size2 = 0;
	mst->capacity1 = mst->capacity2 = 10;
	mst->arr1 = (int*)malloc(sizeof(int) * 10);
	mst->arr2 = (int*)malloc(sizeof(int) * 10);

	return mst;
}

void minStackPush(MinStack* obj, int x) {
	//更新最小值
	if (obj->size2 == 0) {
		obj->arr2[obj->size2++] = x;
	}
	else if (x <= obj->arr2[obj->size2 - 1]) {
		//等于当前最小值也要更新最小值
		if (obj->size2 == obj->capacity2) {
			obj->capacity2 *= 2;
			obj->arr2 = (int*)realloc(obj->arr2, sizeof(int) * obj->capacity2);
		}
		obj->arr2[obj->size2++] = x;
	}

	//x入栈
	if (obj->size1 == obj->capacity1) {
		obj->capacity1 *= 2;
		obj->arr1 = (int*)realloc(obj->arr1, sizeof(int) * obj->capacity1);
	}
	obj->arr1[obj->size1++] = x;
}

void minStackPop(MinStack* obj) {
	if (obj->size1 == 0)
		return;
	//更新最小值
	if (obj->arr1[obj->size1 - 1] == obj->arr2[obj->size2 - 1]) {
		obj->size2--;
	}
	obj->size1--;
}

int minStackTop(MinStack* obj) {
	if (obj->size1 == 0)
		return -1;
	return obj->arr1[obj->size1 - 1];
}

int minStackMin(MinStack* obj) {
	if (obj->size1 == 0)
		return -1;
	return obj->arr2[obj->size2 - 1];
}

void minStackFree(MinStack* obj) {
	free(obj->arr1);
	free(obj->arr2);
	free(obj);
}

int main() {
	return 0;
}