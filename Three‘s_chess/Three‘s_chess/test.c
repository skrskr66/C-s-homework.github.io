#include"chess.h"

int main(){
	srand((unsigned int)time(NULL));
	Init(qipan, ROWS, COLS);
	Choice();
	char winner;
	int a;
	scanf("%d", &a);
	switch (a){
	case 1:
		while (1){
			Show_qipan(qipan, ROWS, COLS);
			Playmove(qipan, ROWS, COLS);
			Show_qipan(qipan, ROWS, COLS);
			winner = CheckWinner(qipan, ROWS, COLS);
			if (winner != ' '){
				break;
			}
			Computermove(qipan, ROWS, COLS);
			winner = CheckWinner(qipan, ROWS, COLS);
		}
		if (winner == 'x'){
			printf("你赢了！\n");
		}
		else if (winner == 'o'){
			printf("电脑赢了！\n");
		}
		else if (winner == 'q'){
			printf("五五开！真厉害！\n");
		}
	case 2:
		system("exit");
	}
	system("pause");
	return 0;
}