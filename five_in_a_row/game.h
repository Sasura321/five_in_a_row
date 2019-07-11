#ifndef __GAME_H__
#define __GAME_H__

# define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROW 10
#define COL 10

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);

#endif  __GAME_H__