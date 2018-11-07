#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void prime(int a){
	if (a == 2){
		printf("It's a prime");
	}
	else {
		for (int i = 3; i <= a; i++){
			if (a%i == 0){
				break;
			}
			printf("It's a prime");
		}
		printf("It's not a prime");
	}
}