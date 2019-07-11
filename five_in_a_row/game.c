#include "game.h"

//��ʼ��
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ���� 
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		printf("  %d ", i + 1);
	}
	printf("\n");
	for (j = 0; j < col; j++)
	{
		printf("---|");
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf(" %d ", i + 1);
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("---|");
		}
		printf("\n");
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������:>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
		else
		{
			continue;
		}
	}
}

//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����:>\n");
	printf("����������(%d,%d): >", row, col);
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("�������Ѿ���ռ��\n");
				printf("����������:>");
				continue;
			}
		}
		else
		{
			printf("����Ƿ�\n");
			printf("����������:>");
			continue;
		}
	}
}

//�ж�ƽ��
static int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col)
{
	//��Ϸ��Ӯ
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 4; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && \
				board[i][j + 2] == board[i][j + 3] && board[i][j + 3] == board[i][j + 4] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row - 4; i++)
		{
			if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && \
				board[i + 2][j] == board[i + 3][j] && board[i + 3][j] == board[i + 4][j] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	for (i = 0; i < row - 4; i++)
	{
		if (board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2] && \
			board[i + 2][i + 2] == board[i + 3][i + 3] && board[i + 3][i + 3] == board[i + 4][i + 4] && board[i][i] != ' ')
		{
			return board[i][i];
		}
		if (board[i][i + 4] == board[i + 1][i + 3] && board[i + 1][i + 3] == board[i + 2][i + 2] && \
			board[i + 2][i + 2] == board[i + 3][i + 1] && board[i + 3][i + 1] == board[i + 4][i] && board[i][i + 4] != ' ')
		{
			return board[i][i + 4];
		}
	}

	//������
	//for (i = 0; i < row; i++)
	//{
	//	for (j = 0; j < col - 2; j++)
	//	{
	//		if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ')
	//		{
	//			return board[i][j];
	//		}
	//	}
	//	for (j = 0; j < col; j++)
	//	{
	//		for (i = 0; i < row - 2; i++)
	//		{
	//			if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i][j] != ' ')
	//			{
	//				return board[i][j];
	//			}
	//		}
	//	}
	//	for (i = 0; i < row - 2; i++)
	//	{
	//		if (board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2] && board[i][i] != ' ')
	//		{
	//			return board[i][i];
	//		}
	//		if (board[i][i + 2] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i] && board[i + 1][i + 1] != ' ')
	//		{
	//			return board[i + 1][i + 1];
	//		}
	//	}

	//��Ϸƽ��
	if (IsFull(board, row, col))
	{
		return 'p';
	}
	//��Ϸ����
	return ' ';

}