#include"sixth.h"

int main(){
	find();
	system("pause");
	return 0;
}







#if 0
int main(){
	while (1){
		printf("输入1，开始游戏\n");
		printf("输入0，退出游戏\n");
		int i = 0;
		scanf("%d", &i);
		if (i == 1){
			Game();
		}
		else if(i == 0){
			printf("goodbye!\n");
			break;
		}
		else{
			printf("请重新输入！\n");
		}
	}
	system("pause");
	return 0;
}
#endif