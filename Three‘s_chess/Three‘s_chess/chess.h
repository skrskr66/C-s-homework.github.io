#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 3
#define COLS 3

char qipan[ROWS][COLS];
//������Ĺ��̣�
//1.��ʼ������
//2.�����ǵ����̳�ʼ��֮��������Ҫ������̲�չʾ����
//3.֮��������Ҫ����ߺ͵����ߣ�ÿ��һ��������Ҫ�����жϣ����Ƿ��ʤ

void Choice(){
	for (int i = 0; i < 41; i++){
		printf("*");
	}
	printf("\n");
	for (int j = 0; j < 10; j++){
		printf("*                                       *\n");
		if (j == 1){
			printf("*              C��������                *\n");
		}
		if (j == 3){
			printf("*              1.��ʼ��Ϸ               *\n");
		}
		if (j == 5){
			printf("*              2.�˳���Ϸ               *\n");
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
	printf("���������\n");
	while (1){
		printf("��������ĸ�ʽΪ0,0\n");
		scanf("%d,%d", &row, &col);
		if (row < 0 || row >= ROWS || col < 0 || col >= COLS){
			printf("������������������\n");
			continue;
		}
		else if (qipan[row][col] != ' '){
			printf("�ô��Ѿ��¹����ˣ�����������\n");
			continue;
		}
		qipan[row][col] = 'x';
		break;
	}
}

void Computermove(char qipan[ROWS][COLS], int row, int col){
	printf("���������\n");
	while (1){
		row = rand() % ROWS;
		col = rand() % COLS;
		if (qipan[row][col] != ' '){
			printf("�ô��������ӣ�����������\n");
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
	//�ж���
	for (int col = 0; col < COLS; col++){
		if (qipan[0][col] == qipan[1][col] && qipan[0][col] == qipan[2][col]
			&& qipan[0][col] != ' '){
			return qipan[0][col];
		}
	}
	//�ж���
	for (int row = 0; row < ROWS; row++){
		if (qipan[row][0] == qipan[row][1] && qipan[row][0] == qipan[row][2]
			&& qipan[row][0] != ' '){
			return qipan[row][0];
		}
	}
	//�ж�б
	if (qipan[0][0] == qipan[1][1] && qipan[0][0] == qipan[2][2]
		&& qipan[0][0] != ' '){
		return qipan[0][0];
	}
	else if (qipan[2][0] == qipan[1][1] && qipan[2][0] == qipan[0][2]
		&& qipan[2][0] != ' '){
		return qipan[2][0];
	}
	//�жϺ���
	else if (Show_full(qipan,row,col)){
		return 'q';
	}
	return ' ';
}

