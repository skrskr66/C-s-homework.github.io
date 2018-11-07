#include<stdio.h>
#include<stdlib.h>

void  LeapYear(int a){
	if (a % 100 == 0 && a % 400 == 0){
		printf("%d is LeapYear", a);
	}
	else if (a % 4 == 0 && a % 100 != 0){
		printf("%d is LeapYear", a);
	}
	else{
		printf("Not LeapYear");
	}
}