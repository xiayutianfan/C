
#include "game.h"

// ��ʼ��
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set){

	int i = 0;
	int j = 0;
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			board[i][j] = set;
		}
	}
}

// ��ӡ����(ֻ��ӡ9*9��С����)
void DisplayBoard(char board[ROWS][COLS], int row, int col){

	int i = 0;
	int j = 0;
	// ��ӡ�к�
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

// �����(9*9������)������
void SetMine(char board[ROWS][COLS], int row, int col){

	int count = EASY_COUNT;
	int x = 0;
	int y = 0;
	// ������,�ɹ�count--(��countΪ0��ʱ��,�˳�ѭ��)
	while(count){
		x = rand() % row + 1;// ����0-9�������
		y = rand() % col + 1;// ����0-9�������

		// ���ֵ��ë��,�����ж�һ��,ֻҪС��0�ʹ���10��ͳͳ�������������.
		//if( (x == 0 || y == 0) || (x >= 10 || y >= 10))
		//	continue;

		// ��Ϊ���ֵ��0��,�����ж�һ��,��0�ͼ�1;
		/*if(0 == x)
			x++;
		if(0 == y)
			y++;*/

		// �����ʼ��Ϊ�ַ�'0',�������ַ�'0'���ж��������Ƿ���ֵ
		if('0' == board[x][y]){
			// �ַ�'1'�������1����
			board[x][y] = '1';
			count--;
		}
	}
}

// ʵ��ɨ��

int get_mine_count(char mine[ROWS][COLS], int x, int y){
	
	// ������Χ���׵ĸ���
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
	
	// ���ռ�������
	int x = 0;
	int y = 0;
	int win = 0;
	// ��������(������9*9 - 10 = 71)
	while(win < row * col - EASY_COUNT){
		printf("�������Ų��׵�����: ");
		scanf("%d%d", &x, &y);
		// �ж�����Ϸ���
		if((x >= 1 && x <= row) && (y >= 1 && y <= col)){
			// ����Ϸ�
			// 1.����
			if(mine[x][y] == '1'){
				printf("���ź�,�㱻ը����\n");
				DisplayBoard(mine, row, col);
				break;
			}else{ //������
				// ����x,y������Χ�м�����
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				win++;
			}

		}else {
			printf("��������Ƿ�,��������\n");
		}
	}
	if(win == row * col - EASY_COUNT)
		printf("���׳ɹ�\n");
	DisplayBoard(mine, row, col);
}