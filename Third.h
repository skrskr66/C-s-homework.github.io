#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void change_num(){
	int a[5] = { 12, 52, 36, 45, 62 };
	int b[5] = { 21, 34, 13, 24, 72 };
	int i = 0;
	int tmp = 0;
	int sz = sizeof(a) / sizeof(a[0]);//所有数据的字节数除以一个数据的字节数等于数组的长度
	for (i = 0; i < sz; i++){
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
	for (i = 0; i < sz; i++){
		printf("%d,", a[i]);
	}
	printf("\n");
	for (i = 0; i < sz; i++){
		printf("%d,", a[i]);
	}
}
void jisuan(){
	double i;//最好改为double类型，因为1/i和1.0/i这两种写法，如果i的类型不同那么得出的答案也不同
	double sum=0,sum1=0,sum2=0; 
	for (i = 1; i < 100; i += 2){
		sum1 = sum1 + 1 / i;
	}
	for (i = 2; i < 101; i += 2){
		sum2 = sum2 - 1 / i;
	}
			sum=sum1+sum2;
			printf("%lf", sum);//%f和%lf分别是float类型和double类型用于格式化输入输出时对应的格式符号。
								//%lf为双精度浮点
}
void js9(){
	int i;
	int count = 0;
	for (i = 0; i < 101; i++){
		if ((i - 9) % 10 == 0||i / 9 == 10 ){
			count++;
		}
	}
	printf("%d", count);
}