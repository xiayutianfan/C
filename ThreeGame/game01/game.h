#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

// 能告诉我们4种游戏状态
// 1.玩家赢了 - 'X' 2.电脑赢了- 'O' 3.平局- 'Q' 4.游戏继续 - 'C'
char IsWin(char board[ROW][COL], int row, int col);