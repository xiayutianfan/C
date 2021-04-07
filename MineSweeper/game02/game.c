
#include "game.h"

// 初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set){

	int i = 0;
	int j = 0;
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			board[i][j] = set;
		}
	}
}

// 打印棋盘(只打印9*9大小棋盘)
void DisplayBoard(char board[ROWS][COLS], int row, int col){

	int i = 0;
	int j = 0;
	// 打印列号
	for(i = 0; i <= col; i++){
		printf("%d ", i);
	}
	printf("\n");
	for(i = 1; i <= row; i++){
		printf("%d ", i);
		for(j = 1; j <= col; j++){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

// 随机在(9*9棋盘里)布置雷
void SetMine(char board[ROWS][COLS], int row, int col){

	int count = EASY_COUNT;
	int x = 0;
	int y = 0;
	// 布置雷,成功count--(当count为0的时候,退出循环)
	while(count){
		x = rand() % row + 1;// 生成0-9的随机数
		y = rand() % col + 1;// 生成0-9的随机数

		// 随机值有毛病,我先判断一下,只要小于0和大于10的统统给我重新随机过.
		//if( (x == 0 || y == 0) || (x >= 10 || y >= 10))
		//	continue;

		// 因为随机值有0的,所以判断一下,是0就加1;
		/*if(0 == x)
			x++;
		if(0 == y)
			y++;*/

		// 数组初始化为字符'0',所以用字符'0'来判断数组里是否有值
		if('0' == board[x][y]){
			// 字符'1'代表放入1个雷
			board[x][y] = '1';
			count--;
		}
	}
}

// 实现扫雷

int get_mine_count(char mine[ROWS][COLS], int x, int y){
	
	// 计算周围的雷的个数
	return mine[x - 1][y] + 
	mine[x + 1][y] +
	mine[x][y - 1] + 
	mine[x][y + 1] + 
	mine[x + 1][y + 1] + 
	mine[x - 1][y - 1] +
	mine[x + 1][y - 1] + 
	mine[x - 1][y + 1] - 8 * '0';

}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col){
	
	// 接收键盘输入
	int x = 0;
	int y = 0;
	int win = 0;
	// 结束条件(棋盘是9*9 - 10 = 71)
	while(win < row * col - EASY_COUNT){
		printf("请输入排查雷的坐标: ");
		scanf("%d%d", &x, &y);
		// 判断坐标合法性
		if((x >= 1 && x <= row) && (y >= 1 && y <= col)){
			// 坐标合法
			// 1.踩雷
			if(mine[x][y] == '1'){
				printf("很遗憾,你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}else{ //不是雷
				// 计算x,y坐标周围有几个雷
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}

		}else {
			printf("输入坐标非法,重新输入\n");
		}
	}
	if(win == row * col - EASY_COUNT)
		printf("排雷成功\n");
	DisplayBoard(mine, row, col);
}