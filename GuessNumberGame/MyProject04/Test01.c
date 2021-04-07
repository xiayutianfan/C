#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>


// 猜数字游戏

//void menu(){
//	printf("------------------------------------\n");
//	printf("	1.play	0.exit	\n");
//	printf("------------------------------------\n");
//}
//
//void game(){
//	// 1.生成一个随机数
//	int ret = 0;
//	int guess = 0;//接收猜的数字
//	//使用时间戳设置随机数生成起始点(因为时间会变化)
//	//time_t time(time_t *time);
//	ret = rand() % 100 + 1;//生成1-100随机数
//	// 2.猜数字
//	while(1){
//		printf("请猜数字>: ");
//		scanf("%d", &guess);
//		if(guess > ret){
//			printf("猜大了\n");
//		} else if(guess < ret){
//			printf("猜小了\n");
//		} else {
//			printf("猜对了\n");
//		}
//	}
//}
//
//int main(){
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do{
//		menu();
//		printf("请选择>: ");
//		scanf("%d",&input);
//		switch(input){
//			case 1:
//				game();// 开始游戏
//				break;
//			case 2:
//				printf("退出游戏\n");
//				break;
//			default:
//				printf("选择错误\n");
//				break;
//		}
//	}while(input);
//
//	return 0;
//}