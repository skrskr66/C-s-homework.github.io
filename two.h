#include<stdio.h>
#include<stdlib.h>

void ChangeNum(int a, int b){
	int temp = 0;
		temp = b;
		b = a;
		a = temp;
		printf("%d,%d", a, b);
}