#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
void Game(){
	int num = 0;
	int result = 0;
	srand((unsigned int)time(NULL));
	result = rand() % 100 + 1;
	do{
		printf("请输入一个数:");
		scanf("%d", &num);
		if (num < result){
			printf("lower\n");
		}
		else if(num > result){
			printf("higher\n");
		}
	} while (num != result);
	printf("congratulations!\n");
}