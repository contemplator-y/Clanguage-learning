#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*
**完成时间2019年11月26日
*/

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10


int  menu()
{
	printf("--------------------------\n");
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("--------------------------\n");
	int choice = 0;
	while (1)
	{
		printf("请输入您的选择:\n");
		scanf("%d", &choice);
		if (choice == 0 || choice == 1)
		{
			return choice;
		}
		printf("您的输入有误,请重新输入!\n");
	}

}

void Print(char showMap[MAX_ROW][MAX_COL])
{
	printf("   ");
	for (int col = 0; col < MAX_COL; col++)
	{
		printf("%c ", col + '0');
	}
	printf("\n--+-----------------\n");
	for (int row = 0; row < MAX_ROW; row++)
	{
		printf("%c |", row + '0');
		for (int col = 0; col < MAX_COL; col++)
		{
			printf("%c ", showMap[row][col]);
		}
		printf("\n");
	}
}

Init(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL])
{
	memset(showMap,'*',MAX_ROW * MAX_COL);
	memset(mineMap, '0', MAX_ROW * MAX_COL);

	int count = MINE_COUNT;
	while (count)
	{
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineMap[row][col] != '1')
		{
			mineMap[row][col] = '1';
			count--;
		}
	}

}

void Input(int* row, int* col)
{
	while (1)
	{
		printf("请输入翻开的坐标:\n");
		scanf("%d %d", row, col);
		if (*row < 0 || *row >= MAX_ROW
			|| *col < 0 || *col >= MAX_COL)
		{
			printf("您的输入有误!\n");
			continue;
		}
		break;
	}
}

int checkMine(char mineMap[MAX_ROW][MAX_COL],int row, int col)
{
	if (mineMap[row][col] == '1')
	{
		return 1;
	}
	return 0;
}
int checkLastBlank(char showMap[MAX_ROW][MAX_COL])
{
	int countx = 0;
	for (int row = 0; row < MAX_ROW; row++)
	{
		for (int col = 0; col < MAX_COL; col++)
		{
			if (showMap[MAX_ROW][MAX_COL] == '*')
			{
				countx++;
			}
		}
	}
	return countx;
}

void Update(char showMap[MAX_ROW][MAX_COL], 
	char mineMap[MAX_ROW][MAX_COL],
	int row,int col)
{
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++)
	{
		for (int c = col - 1; c <= col + 1; c++)
		{
			if (r < 0 || r >= MAX_ROW
				|| c < 0 || c >= MAX_COL)
			{
				continue;
			}
			if (mineMap[r][c] == '1')
			{
				count++;
			}
		}
	}
	showMap[row][col] = count + '0';
}

void Game(char showMap[MAX_ROW][MAX_COL],char mineMap[MAX_ROW][MAX_COL])
{
	Init(showMap,mineMap);
	Print(mineMap);
	while (1)
	{
		system("cls");
		Print(showMap);
		int row = 0;
		int col = 0;
		Input(&row,&col);
		int tmp = checkMine(mineMap,row, col);
		if (tmp)
		{
			Print(mineMap);
			printf("你输了!\n");
			break;
		}
		int countx = checkLastBlank(showMap);
		if (countx == 10)
		{
			printf("恭喜你,你赢了\n");
			break;
		}
		Update(showMap, mineMap,row,col);
	}
	
}
int main()
{
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	srand((unsigned int)time(0));

	int choice = 0;
	while (1)
	{
		choice = menu();
		if (choice)
		{
			Game(showMap,mineMap);
			continue;
		}
		break;
	}
	system("pause");
	return 0;
}