#include<stdio.h>
#include<stdlib.h>
void jisuan(int i){
	int j;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++){
			int sum;
			sum = i*j;
			printf("%d*%d=%d ", j, i, sum);
		}
		printf("\n");
	}
}

void jisuan2(int a){
	int i;
	int count=0;
	for (i = 100; i <= a; i++){
		int j;
		for (j = 2; j < i; j++){
			if (i%j == 0)
			break;
		}
		if (j == i){
			printf("%d\n", i);
			count++;
		}
	}
	printf("%d\n", count);
}
void jisuan3(int b){
	int i;
	int count = 0;
	for (i=1000; i <=b; i++){
		if (i % 4 == 0 && i % 100 != 0){
			printf("%d ", i);
			count++;
		}
		else if(i % 100 == 0 || i % 400 == 0){
			printf("%d ", i);
		}
    }printf("%d", count);
}
