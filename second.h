#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void compare(){
	int a = 10;
	int b = 20;
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
	printf("a=%d,b=%d", a, b);
}
void compare2(){
	int a = 20;
	int b = 10;
	a = a - b;
	b = a + b;
	a = b - a;
	printf("a=%d,b=%d", a, b);
}
void compare3(){
	int a[10] = { 12, 23, 51, 5, 24, 35, 62, 25, 19, 60 };
	int i;
	int max = a[0];
	for (i = 0; i < 11; i++){
		if (max < a[i]){
			max = a[i];		
		}
	}
	printf("最大数为%d", max);
}
void compare4(int a,int b,int c){
	int tmp = 0;
	if (a > b){
		tmp = a;
		a = b;
		b = tmp;
	}
	if (b > c){
		tmp = b;
		b = c;
		c = tmp;
	}
	if (a > b){
		tmp = a;
		a = b;
		b = tmp;
	}
	printf("这三个数的排序为：%d,%d,%d", a, b, c);
}
void compare5(int a,int b){
	int tmp = 0;
	if (a < b){
		tmp = a;
		a = b;
		b = tmp;
	}
	while (a-b!=0){
		tmp = a - b;
		a = b;
		b = tmp;
			if (a < b){
			tmp = a;
			a = b;
			b = tmp;
		}
	}
	printf("最大公约数为：%d", b);
}