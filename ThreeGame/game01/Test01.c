#define _CRT_SECURE_NO_WARNINGS 1;
#include "game.h"

// 测试三子棋游戏
// 菜单
void menu(){
	printf("- - - - - - - - - - - - - - \n");
	printf("---	1.play	0. exit	---\n");
	printf("- - - - - - - - - - - - - - \n");
}


// 游戏的整个实现
void game(){

	char ret = 0;
	// 数组-存放走出的棋盘信息
	char board[ROW][COL] = {0};//初始化全部空格
	// 初始化棋盘
	InitBoard(board, ROW, COL);
	// 打印棋盘
	DisplayBoard(board, ROW, COL);
	// 开始下棋
	while(1){
		// 玩家下棋
		PlayerMove(board, ROW, COL);
		// 走完打印一下
		DisplayBoard(board, ROW, COL);
		// 判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if('C' != ret){
			break;
		}
		// 电脑下棋
		ComputerMove(board, ROW, COL);
		// 走完打印一下
		DisplayBoard(board, ROW, COL);
		// 判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if('C' != ret){
			break;
		}
	}

	if('X' == ret){
		printf("玩家赢\n");
	}else if('O' == ret){
		printf("电脑赢\n");
	}else{
		printf("平局\n");
	}
}

void test(){
	int input = 0;
	// 设置随机值
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请选择: ");
		scanf("%d",&input);
		switch(input){
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误,请重新选择\n");
				break;
		}
	}while(input);//输入"非零"为"真"会继续循环
	
}

int main(){
	test();
	return 0;
}