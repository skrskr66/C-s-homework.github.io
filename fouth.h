#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void star(){//将代码分为上三角和下三角来输出
	int i, j, n = 7;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 6; i > 0 ; i--)
	{
		for (j = 1; j <= n-i; j++)
		{
			printf(" ");
		}
		for (j = 1; j < 2 * i ; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}
void narcissus(){
	int i;
	int j, k, l;
	for (i = 0; i < 1000; i++)
	{
		j = i % 10;
		k = (i / 10) % 10;
		l = i / 100;
		if (i == j * j * j + k * k * k + l * l * l ){//老铁！注意是"=="!!
			printf("%d\n", i);
		}
	}
}
void he(int a){//j每次都是j*10，之后在加上a。
	int Sn = 0, i, j;
	j = a;//j=a，定义在循环之外，a的赋值只在第一次填写参数时。
	for (i = 0; i < 5; i++){
		Sn = j+ Sn;
		j = j * 10 + a;
	}
	printf("%d", Sn);
}