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
	printf("��������ϵ�˵�������\n");
	scanf("%s", ab->person[ab->size].name);
	printf("��������ϵ�˵ĵ绰��\n");
	scanf("%s", &ab->person[ab->size].number);
	printf("��������ϵ�˵��Ա�\n");
	scanf("%s", ab->person[ab->size].sex);
	printf("��������ϵ�˵����䣺\n");
	scanf("%d", &ab->person[ab->size].age);
	printf("��������ϵ�˵�סַ��\n");
	scanf("%s", ab->person[ab->size].address);
	ab->size++;
	printf("�����ϵ�˳ɹ���\n");
}

void delPersonInfor(addressBook* ab) {
	if (ab->size == 0) {
		printf("ͨѶ¼Ϊ��,ɾ����ϵ��ʧ�ܣ�\n");
		return;
	}
	printf("��������Ҫɾ������ϵ�˵���ţ�\n");
	int i = 0;
	while (1) {
		scanf("%d", &i);
		if (i < 0 || i >= ab->size) {
			printf("����������������������\n");
			continue;
		}
		strcpy(ab->person[i].name,ab->person[ab->size - 1].name);
		strcpy(ab->person[i].number, ab->person[ab->size - 1].number);
		strcpy(ab->person[i].sex, ab->person[ab->size - 1].sex);
		ab->person[i].age = ab->person[ab->size - 1].age;
		strcpy(ab->person[i].address, ab->person[ab->size - 1].address);
		ab->size--;
		printf("ɾ����ϵ�˳ɹ���\n");
		break;
	}
}

void searchPersonInfor(addressBook* ab) {
	printf("�����������ҵ���ϵ�˵ĵ绰��\n");
	char number[1024];
	scanf("%s", number);
	for (int i = 0; i < ab->size; i++) {
		if (strcmp(number, ab->person[i].number) == 0) {
			printf("����ϵ�����ڵ����Ϊ\n");
			printf("%d\n", i);
			printf("����ϵ�˵�����Ϊ��\n");
			printf("%s\n", ab->person[i].name);
			printf("����ϵ�˵ĵ绰Ϊ��\n");
			printf("%s\n", ab->person[i].number);
			printf("����ϵ�˵�����Ϊ��\n");
			printf("%d\n", ab->person[i].age);
			printf("����ϵ�˵��Ա�Ϊ��\n");
			printf("%s\n", ab->person[i].sex);
			printf("����ϵ�˵�סַΪ��\n");
			printf("%s\n", ab->person[i].address);
			return;
		}
	}
	printf("û������Ҫ���ҵ���ϵ��\n");
}

void alterPersonInfor(addressBook* ab) {
	printf("��������Ҫ�޸ĵ���ϵ�˵���ţ�\n");
	int i = 0;
	while (1) {
		scanf("%d", &i);
		if (i < 0 || i >= ab->size) {
			printf("����������������������\n");
			continue;
		}
		char name[1024];
		printf("�������޸ĺ������:��*��ʾ����)\n");
		scanf("%s", name);
		if (strcmp(name, "*") != 0) {
			strcpy(ab->person[i].name,name);
		}
		printf("�������޸ĺ�ĵ绰:��*��ʾ���䣩\n");
		char number[1024];
		scanf("%s", number);
		if (strcmp(number, "*") != 0) {
			strcpy(ab->person[i].number, number);
		}
		printf("�������޸ĺ���Ա�:��*��ʾ���䣩\n");
		char sex[3];
		scanf("%s", sex);
		if (strcmp(sex, "*") != 0) {
			strcpy(ab->person[i].sex, sex);
		}
		printf("�������޸ĺ������:\n");
		int age;
		scanf("%d", &age);
		ab->person[i].age = age;
		printf("�������޸ĺ��סַ:��*��ʾ���䣩\n");
		char address[1024];
		scanf("%s", address);
		if (strcmp(address, "*") != 0) {
			strcpy(ab->person[i].address, address);
		}
		printf("�޸���ϵ����Ϣ�ɹ���\n");
		break;
	}
}

void printAllPersonInfor(addressBook* ab) {
	printf("   ����\t  �绰\t  �Ա�\t  ����\t  סַ\n");
	for (int i = 0; i < ab->size; i++) {
		printf("[%d] %s\t%s\t%s\t%d\t%s\n", i,ab->person[i].name, ab->person[i].number,
			ab->person[i].sex, ab->person[i].age, ab->person[i].address);
	}
}

void clearAllPersonInfor(addressBook* ab) {
	ab->size = 0;
	printf("�����ϵ�˳ɹ���\n");
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
	printf("\n\n----------ͨѶ¼�˵�------------\n");
	printf("1.�����ϵ����Ϣ\n");
	printf("2.ɾ��ָ����ϵ����Ϣ\n");
	printf("3.������ϵ����Ϣ\n");
	printf("4.�޸�ָ����ϵ����Ϣ\n");
	printf("5.��ʾ������ϵ����Ϣ\n");
	printf("6.���������ϵ��\n");
	printf("7.����������������ϵ��\n");
	printf("0.�˳�\n");
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
		printf("������Ҫִ�еķ�����\n");
		scanf("%d", &choice);
		if (choice < 0 || choice > 7) {
			printf("����������������������\n");
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