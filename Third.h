#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void change_num(){
	int a[5] = { 12, 52, 36, 45, 62 };
	int b[5] = { 21, 34, 13, 24, 72 };
	int i = 0;
	int tmp = 0;
	int sz = sizeof(a) / sizeof(a[0]);//�������ݵ��ֽ�������һ�����ݵ��ֽ�����������ĳ���
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
	double i;//��ø�Ϊdouble���ͣ���Ϊ1/i��1.0/i������д�������i�����Ͳ�ͬ��ô�ó��Ĵ�Ҳ��ͬ
	double sum=0,sum1=0,sum2=0; 
	for (i = 1; i < 100; i += 2){
		sum1 = sum1 + 1 / i;
	}
	for (i = 2; i < 101; i += 2){
		sum2 = sum2 - 1 / i;
	}
			sum=sum1+sum2;
			printf("%lf", sum);//%f��%lf�ֱ���float���ͺ�double�������ڸ�ʽ���������ʱ��Ӧ�ĸ�ʽ���š�
								//%lfΪ˫���ȸ���
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