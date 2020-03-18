#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct personInfor {
	char name[1024];
	char sex[3];
	char number[1024];
	int age;
	char address[1024];
} personInfor;

typedef struct addressBook {
    personInfor person[1000];
	int size;
} addressBook;

void initAddBook(addressBook* ab) {
	ab->size = 0;
}

void addPersonInfor(addressBook* ab) {
	printf("请输入联系人的姓名：\n");
	scanf("%s", ab->person[ab->size].name);
	printf("请输入联系人的电话：\n");
	scanf("%s", &ab->person[ab->size].number);
	printf("请输入联系人的性别：\n");
	scanf("%s", ab->person[ab->size].sex);
	printf("请输入联系人的年龄：\n");
	scanf("%d", &ab->person[ab->size].age);
	printf("请输入联系人的住址：\n");
	scanf("%s", ab->person[ab->size].address);
	ab->size++;
	printf("添加联系人成功！\n");
}

void delPersonInfor(addressBook* ab) {
	if (ab->size == 0) {
		printf("通讯录为空,删除联系人失败！\n");
		return;
	}
	printf("请输入您要删除的联系人的序号：\n");
	int i = 0;
	while (1) {
		scanf("%d", &i);
		if (i < 0 || i >= ab->size) {
			printf("您的输入有误，请重新输入\n");
			continue;
		}
		strcpy(ab->person[i].name,ab->person[ab->size - 1].name);
		strcpy(ab->person[i].number, ab->person[ab->size - 1].number);
		strcpy(ab->person[i].sex, ab->person[ab->size - 1].sex);
		ab->person[i].age = ab->person[ab->size - 1].age;
		strcpy(ab->person[i].address, ab->person[ab->size - 1].address);
		ab->size--;
		printf("删除联系人成功！\n");
		break;
	}
}

void searchPersonInfor(addressBook* ab) {
	printf("请输入您查找的联系人的电话：\n");
	char number[1024];
	scanf("%s", number);
	for (int i = 0; i < ab->size; i++) {
		if (strcmp(number, ab->person[i].number) == 0) {
			printf("该联系人所在的序号为\n");
			printf("%d\n", i);
			printf("该联系人的姓名为：\n");
			printf("%s\n", ab->person[i].name);
			printf("该联系人的电话为：\n");
			printf("%s\n", ab->person[i].number);
			printf("该联系人的年龄为：\n");
			printf("%d\n", ab->person[i].age);
			printf("该联系人的性别为：\n");
			printf("%s\n", ab->person[i].sex);
			printf("该联系人的住址为：\n");
			printf("%s\n", ab->person[i].address);
			return;
		}
	}
	printf("没有您所要查找的联系人\n");
}

void alterPersonInfor(addressBook* ab) {
	printf("请输入您要修改的联系人的序号：\n");
	int i = 0;
	while (1) {
		scanf("%d", &i);
		if (i < 0 || i >= ab->size) {
			printf("您的输入有误，请重新输入\n");
			continue;
		}
		char name[1024];
		printf("请输入修改后的姓名:（*表示不变)\n");
		scanf("%s", name);
		if (strcmp(name, "*") != 0) {
			strcpy(ab->person[i].name,name);
		}
		printf("请输入修改后的电话:（*表示不变）\n");
		char number[1024];
		scanf("%s", number);
		if (strcmp(number, "*") != 0) {
			strcpy(ab->person[i].number, number);
		}
		printf("请输入修改后的性别:（*表示不变）\n");
		char sex[3];
		scanf("%s", sex);
		if (strcmp(sex, "*") != 0) {
			strcpy(ab->person[i].sex, sex);
		}
		printf("请输入修改后的年龄:\n");
		int age;
		scanf("%d", &age);
		ab->person[i].age = age;
		printf("请输入修改后的住址:（*表示不变）\n");
		char address[1024];
		scanf("%s", address);
		if (strcmp(address, "*") != 0) {
			strcpy(ab->person[i].address, address);
		}
		printf("修改联系人信息成功！\n");
		break;
	}
}

void printAllPersonInfor(addressBook* ab) {
	printf("   姓名\t  电话\t  性别\t  年龄\t  住址\n");
	for (int i = 0; i < ab->size; i++) {
		printf("[%d] %s\t%s\t%s\t%d\t%s\n", i,ab->person[i].name, ab->person[i].number,
			ab->person[i].sex, ab->person[i].age, ab->person[i].address);
	}
}

void clearAllPersonInfor(addressBook* ab) {
	ab->size = 0;
	printf("清空联系人成功！\n");
}

int cmp_personInfor(const void* _a, const void* _b) {
	personInfor* a = (personInfor*)_a;
	personInfor* b = (personInfor*)_b;
	return strcmp(a->name, b->name);
}
void sortAllPersonInfor(addressBook* ab) {
	qsort(ab->person, ab->size, sizeof(ab->person[0]), cmp_personInfor);
}

void menu() {
	printf("\n\n----------通讯录菜单------------\n");
	printf("1.添加联系人信息\n");
	printf("2.删除指定联系人信息\n");
	printf("3.查找联系人信息\n");
	printf("4.修改指定联系人信息\n");
	printf("5.显示所有联系人信息\n");
	printf("6.清空所有联系人\n");
	printf("7.以名字排序所有联系人\n");
	printf("0.退出\n");
}

typedef void(*Func)(addressBook*);

int main() {
	Func f[8] = {
		NULL,
		addPersonInfor,
		delPersonInfor,
		searchPersonInfor,
		alterPersonInfor,
		printAllPersonInfor,
		clearAllPersonInfor,
		sortAllPersonInfor
	};
	int choice = 0;
	addressBook *ab = (addressBook*)malloc(sizeof(addressBook));
	initAddBook(ab);
	while (1) {
		menu();
		printf("请输入要执行的方法：\n");
		scanf("%d", &choice);
		if (choice < 0 || choice > 7) {
			printf("您的输入有误，请重新输入\n");
			continue;
		}
		if (choice == 0) {
			break;
		}
		f[choice](ab);
	
	}
	
	system("pause");
	return 0;
}