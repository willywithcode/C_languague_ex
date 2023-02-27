#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main () {
	int r;
	int number;
	srand(time(NULL));
	r = rand()%10;
	do {
		printf("Your number: ");
		scanf("%d",&number);
		int minus = number - r;
		switch(minus){
			case -9 ... -1: printf("bigger\n");break;
			case 1 ... 9: printf("smaller\n");break;
			default: break;
		}
	} while(number != r);
	printf("You got it\n");

	
}
