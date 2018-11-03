#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<windows.h>
void login(){
	char pass[1024] = {};
	char password[] = "123456";
		for (int i = 0; i < 3; i++){
			printf("Please enter you password:\n");
				scanf("%s", &pass);
		if (strcmp(password, pass) == 0){
			printf("Welcome to system!\n");
			break;
		}
	}printf("sorry,exiting");
}