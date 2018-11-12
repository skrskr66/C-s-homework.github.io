#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 3
#define COLS 3

char qipan[ROWS][COLS];
//三子棋的过程：
//1.初始化棋子
//2.当我们的棋盘初始化之后，我们需要设计棋盘并展示棋盘
//3.之后我们需要玩家走和电脑走，每走一步我们需要进行判断，看是否获胜

void Choice(){
	for (int i = 0; i < 41; i++){
		printf("*");
	}
	printf("\n");
	for (int j = 0; j < 10; j++){
		printf("*                                       *\n");
		if (j == 1){
			printf("*              C版三子棋                *\n");
		}
		if (j == 3){
			printf("*              1.开始游戏               *\n");
		}
		if (j == 5){
			printf("*              2.退出游戏               *\n");
		}
	}
	for (int i = 0; i < 41; i++){
		printf("*");
	}
	printf("\n");
}

void Init(char qipan[ROWS][COLS],int row,int col){
	for (int row = 0; row < ROWS; ++row){
		for (int col = 0; col < COLS; ++col){
			qipan[row][col] = ' ';
		}
	}
}

void Show_qipan(char qipan[ROWS][COLS], int row, int col){
	for (int i = 0; i < row; ++i){
		printf("| %c | %c | %c |\n", qipan[i][0], 
			qipan[i][1], qipan[i][2]);
		if (i != row - 1){
			printf("|---|---|---|\n");
		}
	}
}

void Playmove(char qipan[ROWS][COLS], int row, int col){
	printf("请玩家下子\n");
	while (1){
		printf("例如输入的格式为0,0\n");
		scanf("%d,%d", &row, &col);
		if (row < 0 || row >= ROWS || col < 0 || col >= COLS){
			printf("输入有误，请重新输入\n");
			continue;
		}
		else if (qipan[row][col] != ' '){
			printf("该处已经下过子了，请重新输入\n");
			continue;
		}
		qipan[row][col] = 'x';
		break;
	}
}

void Computermove(char qipan[ROWS][COLS], int row, int col){
	printf("请电脑下子\n");
	while (1){
		row = rand() % ROWS;
		col = rand() % COLS;
		if (qipan[row][col] != ' '){
			printf("该处已有棋子，请重新填入\n");
			continue;
		}
		qipan[row][col] = 'O';
		break;
	}
}

static int Show_full(char qipan[ROWS][COLS], int row, int col){
	int i, j;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			if (qipan[i][j] == ' '){
				return 0;
			}
		}
	}
	return 1;
}

char CheckWinner(char qipan[ROWS][COLS], int row, int col){
	//判断行
	for (int col = 0; col < COLS; col++){
		if (qipan[0][col] == qipan[1][col] && qipan[0][col] == qipan[2][col]
			&& qipan[0][col] != ' '){
			return qipan[0][col];
		}
	}
	//判断列
	for (int row = 0; row < ROWS; row++){
		if (qipan[row][0] == qipan[row][1] && qipan[row][0] == qipan[row][2]
			&& qipan[row][0] != ' '){
			return qipan[row][0];
		}
	}
	//判断斜
	if (qipan[0][0] == qipan[1][1] && qipan[0][0] == qipan[2][2]
		&& qipan[0][0] != ' '){
		return qipan[0][0];
	}
	else if (qipan[2][0] == qipan[1][1] && qipan[2][0] == qipan[0][2]
		&& qipan[2][0] != ' '){
		return qipan[2][0];
	}
	//判断和棋
	else if (Show_full(qipan,row,col)){
		return 'q';
	}
	return ' ';
}

