#include<stdio.h>
#include<stdlib.h>
#define size 5
//�����ʼ�� ���Ƕ������������ͬʱ�����е�����Ԫ�ظ�ֵ�������Ǹ����Ԫ��ͬʱ��ֵ
void init(){
	int arr[size] = { 20, 16, 23, 75, 95, };
	for (int i = 0; i < size; i++){
		printf("arr[%d]=%2d \n", i, arr[i]);
	}
	printf("\n");
}

void empty(){
	int arr[5] = { 20, 16, 23, 75, 95, };
	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++){
		arr[i] = '\0';
		printf("arr[%d]=%2d \n", i, arr[i]);
	}
	printf("\n");
}
void reverse(){
	int temp = 0;
	int i = 0;
	int arr[5] = { 20, 16, 23, 75, 95, };
	for (i = 0; i < 3; i++){
		temp = arr[i];
		arr[i] = arr[4 - i];
		 arr[4 - i] = temp;
		 }
	for (i = 0; i < 5; i++){
		printf("arr[%d]=%2d \n",i, arr[i]);
	}
}