#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
void find(){
	int arr[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;//��һ����Ϊ�����±����
	int i = 0;
	int mid = (left + right) / 2;
	printf("����һ�����ֽ��в��ң�");
	scanf("%d", &i);
	while (left <= right){//�������С���ұ����������	
		mid = (left + right) / 2;
		if (arr[mid] < i){
			left =mid + 1;
		}
		else if(arr[mid] > i){
			right = mid - 1;
		}
		else{
			break;
		}
	}
	if (arr[mid] == i){
		printf("%d", mid);
	}
	else{
		printf("-1");
	}
}