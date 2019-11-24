#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


#define MAX_ROW 3
#define MAX_COL 3

int Menu()
{
	printf("-------------------\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("-------------------\n");
	printf("����������ѡ��:\n");
	int choice = 0;
	while (1)
	{
		scanf("%d", &choice);
		if (choice == 0 || choice == 1)
		{
			break;
		}
		printf("������������,����������!\n");

	}
	return choice;
}

void Init(char chessBroad[MAX_ROW][MAX_COL])
{
	memset(chessBroad, ' ', MAX_ROW * MAX_COL);
}

void printBoard(char chessBroad[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++)
	{
		printf("+--+--+--+\n");
		for (int col = 0; col < MAX_COL; col++)
		{
			printf("| %c", chessBroad[row][col]);
		}
		printf("|\n");
	}
	printf("+--+--+--+\n");

}

void playerMove(char chessBroad[MAX_ROW][MAX_COL])
{
	while (1)
	{
		int row = 0;
		int col = 0;
		printf("���������ӵ����꣨0-2��0-2��:\n");
		scanf("%d %d", &row, &col);
		if (col >= 0 && col < MAX_COL
			&& row >= 0 && row < MAX_ROW && chessBroad[row][col] == ' ')
		{
			chessBroad[row][col] = 'x';
			return;
		}
		printf("������������,����������!\n");
	}
}

void computerMove(char chessBroad[MAX_ROW][MAX_COL])
{
	while (1)
	{
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chessBroad[row][col] == ' ')
		{
			chessBroad[row][col] = 'o';
			printBoard(chessBroad);
			return;
		}
	}
}

//�����Ϸ�Ƿ����,����x��ʾ��һ�ʤ,����o��ʾ���Ի�ʤ,h��ʾ����,����n��ʾ��Ϸ��δ����
char checkWin(char chessBroad[MAX_ROW][MAX_COL])
{
	//��һ�ʤ
	for (int row = 0; row < MAX_ROW; row++)
	{
		if (chessBroad[row][0] == chessBroad[row][1]
			&& chessBroad[row][0] == chessBroad[row][2]
			&& chessBroad[row][0] == 'x')
		{
			return 'x';
		}
	}
	for (int col = 0; col < MAX_COL; col++)
	{
		if (chessBroad[0][col] == chessBroad[1][col]
			&& chessBroad[0][col] == chessBroad[2][col]
			&& chessBroad[0][col] == 'x')
		{
			return 'x';
		}
	}

	if (chessBroad[0][0] == chessBroad[1][1]
		&& chessBroad[0][0] == chessBroad[2][2]
		&& chessBroad[0][0] == 'x')
	{
		return 'x';
	}
	if (chessBroad[0][2] == chessBroad[1][1]
		&& chessBroad[0][2]  == chessBroad[2][0]
		&& chessBroad[0][2] == 'x')
	{
		return 'x';
	}

	//���Ի�ʤ
	for (int row = 0; row < MAX_ROW; row++)
	{
		if (chessBroad[row][0] == 'o'
			&& chessBroad[row][1] == 'o'
			&& chessBroad[row][2] == 'o')
		{
			return 'o';
		}
	}
	for (int col = 0; col < MAX_COL; col++)
	{
		if (chessBroad[0][col] == 'o'
			&& chessBroad[1][col] == 'o'
			&& chessBroad[2][col] == 'o')
		{
			return 'o';
		}
	}

	if (chessBroad[0][0] == 'o'
		&& chessBroad[1][1] == 'o'
		&& chessBroad[2][2] == 'o')
	{
		return 'o';
	}
	if (chessBroad[0][2] == 'o'
		&& chessBroad[1][1] == 'o'
		&& chessBroad[2][0] == 'o')
	{
		return 'o';
	}
	//����
	int num = 0;
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			if (chessBroad[row][col] == ' ')
			{
				num++;
			}
		}
	}
	if (num == 0)
	{
		return 'h';
	}

	return 'n';
}

void Game(char chessBroad[MAX_ROW][MAX_COL])
{
	Init(chessBroad);  //��ʼ������
	printBoard(chessBroad);
	while (1)
	{
		playerMove(chessBroad);
		char tmp = checkWin(chessBroad);
		if (tmp == 'x')
		{
			printf("��ϲ��,��Ӯ��!\n");
			return;
		}
		else if (tmp == 'h')
		{
			printf("�����,�͵������忪!\n");
			return;
		}

		computerMove(chessBroad);
		
		 tmp = checkWin(chessBroad);
		 if (tmp == 'o')
		{
			printf("�����,���Զ��²���!\n");
			return;
		}
	}

}

int main()
{
	char chessbroad[MAX_ROW][MAX_COL] = {0};
	srand((unsigned int)time(0));
	while (1)
	{
		int choice = Menu();
		if (choice  == 1)
		{
			Game(chessbroad);
			continue;
		}
		break;
	}

	system("pause");
	return 0;
}