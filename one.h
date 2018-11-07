#include<stdio.h>
#include<stdlib.h>

void MultiplicationTable(int a){
	for (int i = 1; i <= a; i++){
		for (int j = 1; j <= i; j++){
			int k = 0;
			k = j*i;
			printf("%d*%d=%d ", j,i,k);
		}
		printf("\n");
	}
}