#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void star(){//�������Ϊ�����Ǻ������������
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
		if (i == j * j * j + k * k * k + l * l * l ){//������ע����"=="!!
			printf("%d\n", i);
		}
	}
}
void he(int a){//jÿ�ζ���j*10��֮���ڼ���a��
	int Sn = 0, i, j;
	j = a;//j=a��������ѭ��֮�⣬a�ĸ�ֵֻ�ڵ�һ����д����ʱ��
	for (i = 0; i < 5; i++){
		Sn = j+ Sn;
		j = j * 10 + a;
	}
	printf("%d", Sn);
}