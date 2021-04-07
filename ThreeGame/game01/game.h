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

// �ܸ�������4����Ϸ״̬
// 1.���Ӯ�� - 'X' 2.����Ӯ��- 'O' 3.ƽ��- 'Q' 4.��Ϸ���� - 'C'
char IsWin(char board[ROW][COL], int row, int col);