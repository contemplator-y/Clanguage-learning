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
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("-------------------\n");
	printf("请输入您的选择:\n");
	int choice = 0;
	while (1)
	{
		scanf("%d", &choice);
		if (choice == 0 || choice == 1)
		{
			break;
		}
		printf("您的输入有误,请重新输入!\n");

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
		printf("请输入落子的坐标（0-2，0-2）:\n");
		scanf("%d %d", &row, &col);
		if (col >= 0 && col < MAX_COL
			&& row >= 0 && row < MAX_ROW && chessBroad[row][col] == ' ')
		{
			chessBroad[row][col] = 'x';
			return;
		}
		printf("您的输入有误,请重新输入!\n");
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

//检查游戏是否结束,返回x表示玩家获胜,返回o表示电脑获胜,h表示和棋,返回n表示游戏尚未结束
char checkWin(char chessBroad[MAX_ROW][MAX_COL])
{
	//玩家获胜
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

	//电脑获胜
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
	//和棋
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
	Init(chessBroad);  //初始化棋盘
	printBoard(chessBroad);
	while (1)
	{
		playerMove(chessBroad);
		char tmp = checkWin(chessBroad);
		if (tmp == 'x')
		{
			printf("恭喜你,你赢了!\n");
			return;
		}
		else if (tmp == 'h')
		{
			printf("你真菜,和电脑五五开!\n");
			return;
		}

		computerMove(chessBroad);
		
		 tmp = checkWin(chessBroad);
		 if (tmp == 'o')
		{
			printf("你真菜,电脑都下不过!\n");
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