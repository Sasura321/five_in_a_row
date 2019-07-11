#include "game.h"

menu()
{
	printf("\n");
	printf("*******************************\n");
	printf("****  欢迎来到五子棋游戏！ ****\n");
	printf("****      1.进入游戏       ****\n");
	printf("****      0.退出游戏       ****\n");
	printf("*******************************\n");
}

void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	while (1)
	{
		ComputerMove(board, ROW, COL); //电脑走
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		system("CLS"); //清屏，优化界面
		DisplayBoard(board, ROW, COL); //打印棋盘
		printf("\n");
		PlayerMove(board, ROW, COL); //玩家走
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL); //打印棋盘
		printf("\n");
	}
	if (ret == 'p')
	{
		printf("平局\n");
		DisplayBoard(board, ROW, COL); //打印棋盘
	}
	else if (ret == 'x')
	{
		printf("玩家赢\n");
		DisplayBoard(board, ROW, COL); //打印棋盘
	}
	else if (ret == '0')
	{
		printf("电脑赢\n");
		DisplayBoard(board, ROW, COL); //打印棋盘
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}