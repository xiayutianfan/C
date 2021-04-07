
#include "game.h"

//扫雷游戏

void menu(){

	printf("----------------------\n");
	printf("-----	1.play	----\n");
	printf("-----	0.exit	----\n");
	printf("----------------------\n");
}

//	游戏实现
void game(){

	// 雷的信息存储
	// 1.布置好雷的信息
	char mine[ROWS][COLS] = {0};// 11*11
	// 2.排查出雷的信息
	char show[ROWS][COLS] = {0};
	// 初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	// 打印棋盘(9*9)
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	// 布置雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	// 扫雷
	FindMine(mine, show, ROW, COL);

}

void test(){
	int input = 0;
	// 产生随机数生成器
	srand((unsigned int) time(NULL));
	do{
		menu();
		printf("请选择: ");
		scanf("%d", &input);
		switch(input){
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误,请重新选择\n");
				break;
		}
	}while(input);
}

int main(){
	test();
	return 0;
}