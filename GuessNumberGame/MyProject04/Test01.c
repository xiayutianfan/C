#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>


// ��������Ϸ

//void menu(){
//	printf("------------------------------------\n");
//	printf("	1.play	0.exit	\n");
//	printf("------------------------------------\n");
//}
//
//void game(){
//	// 1.����һ�������
//	int ret = 0;
//	int guess = 0;//���ղµ�����
//	//ʹ��ʱ������������������ʼ��(��Ϊʱ���仯)
//	//time_t time(time_t *time);
//	ret = rand() % 100 + 1;//����1-100�����
//	// 2.������
//	while(1){
//		printf("�������>: ");
//		scanf("%d", &guess);
//		if(guess > ret){
//			printf("�´���\n");
//		} else if(guess < ret){
//			printf("��С��\n");
//		} else {
//			printf("�¶���\n");
//		}
//	}
//}
//
//int main(){
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do{
//		menu();
//		printf("��ѡ��>: ");
//		scanf("%d",&input);
//		switch(input){
//			case 1:
//				game();// ��ʼ��Ϸ
//				break;
//			case 2:
//				printf("�˳���Ϸ\n");
//				break;
//			default:
//				printf("ѡ�����\n");
//				break;
//		}
//	}while(input);
//
//	return 0;
//}