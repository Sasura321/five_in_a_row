#include "game.h"

menu()
{
	printf("\n");
	printf("*******************************\n");
	printf("****  ��ӭ������������Ϸ�� ****\n");
	printf("****      1.������Ϸ       ****\n");
	printf("****      0.�˳���Ϸ       ****\n");
	printf("*******************************\n");
}

void game()
{
	int ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	while (1)
	{
		ComputerMove(board, ROW, COL); //������
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		system("CLS"); //�������Ż�����
		DisplayBoard(board, ROW, COL); //��ӡ����
		printf("\n");
		PlayerMove(board, ROW, COL); //�����
		ret = IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL); //��ӡ����
		printf("\n");
	}
	if (ret == 'p')
	{
		printf("ƽ��\n");
		DisplayBoard(board, ROW, COL); //��ӡ����
	}
	else if (ret == 'x')
	{
		printf("���Ӯ\n");
		DisplayBoard(board, ROW, COL); //��ӡ����
	}
	else if (ret == '0')
	{
		printf("����Ӯ\n");
		DisplayBoard(board, ROW, COL); //��ӡ����
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}