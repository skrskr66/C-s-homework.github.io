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
			printf("��Ӯ�ˣ�\n");
		}
		else if (winner == 'o'){
			printf("����Ӯ�ˣ�\n");
		}
		else if (winner == 'q'){
			printf("���忪����������\n");
		}
	case 2:
		system("exit");
	}
	system("pause");
	return 0;
}