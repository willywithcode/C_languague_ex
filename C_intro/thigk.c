#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void Frequency(){
	int n; 
    // size of array n > 0
	do{
		printf("Enter n (0<=n<=20): ");
		scanf("%d", &n);
	}while (n < 0 || n > 20);
	int arr[n]; 
	int max = 0; 
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		if (arr[i] > max) max = arr[i];
	}
    // the occurency of number
	int appear[max+1]; 
    // check if number is checked
	int checked[max + 1]; 
    // order set of number
	int temp_array[n]; 
    // size of temp_array
	int size = 0; 

	for (int i = 0; i < max + 1; i++){
		appear[i] = 0;
		checked[i] = 0;
	}
	for (int i = 0; i < n; i++){
		appear[arr[i]]++;
		if (!checked[arr[i]]){
			checked[arr[i]] = 1;
			temp_array[size++] = arr[i];
		}
	}
	for (int i = 0; i < size; i++){
		printf("%d %d\n", temp_array[i], appear[temp_array[i]]);
	}
	printf("\n");
}

void Fibonacci() {
    int fibo[100];// array fibonacci
    fibo[0] = 0;//asigh fibonacci first
    fibo[1] = 1;//asigh fibonacci second
    int n;
    printf("Input n: ");scanf("%d",&n);
    for (int i = 2; i < n; i ++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    printf("%d\n",fibo[n-1]);
}
void Matrix() {
    int n;
    printf("Input n ");
    scanf("%d",&n);
    int matrix[n][n];
    int check = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            printf("\nmatrix[%d][%d] = ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    for (int i = 0 ;i < n; i ++) {
        for (int j = 0; j <n ; j ++) {
            if (j != i && matrix[i][j] != 0) check = 1;
            if(j == i && matrix[i][j] != 1) check =1;
        }
    }
    if (check == 1) {
        printf("Not a unit matrix\n");
    }
    else {
        printf("A unit matrix\n");
    }

}
void Date(){
	int date, month, year;
	scanf("%d/%d/%d", &date, &month, &year);
	int checkleap = 0; 
	if (year % 400 == 0){
		checkleap = 1;
	}
	else if (year % 100 == 0){
		checkleap = 0;
	}
	else if (year % 4 == 0){
		checkleap = 1;
	}
	else checkleap = 0;
	int valid = 1; 
	switch(month){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if ((date < 1 || date > 31)){
				valid = 0;
			}else{
				if (date == 31){
					if (month == 12){
						year++;
						date = 1;
						month = 1;
					}
					else{
						month++;
						date = 1;
					}
				}
				else date++;
			}
			break;
		case 2:
			if (checkleap == 0){
				if (date < 1 || date > 28) valid = 0;
				else{
					if (date == 28){
						date = 1;
						month++;
					}
					else date++;
				}
			}
			else{
				if (date < 1 || date > 29) valid = 0;
				else{
					if (date == 29){
						date = 1;
						month++;
					}
					else date++;
				}
			}
			break;

		case 4: case 6: case 9: case 11:
			if (date < 1 || date > 30){
				valid = 0;
			}
			else if (date == 30){
					month++;
				date = 1;
			}
			else date++;
			break;
		default:
			valid = 0;
	}
	if (valid == 0){
		printf("INVALID\n\n");
		return;
	}
	else printf("%d/%d/%d\n\n", date, month, year);
}

int main() {
    int n;
    while(1) {
        do {
            printf("Select options: \n1. Frequency.\n2. Fibonacci.\n3. Password.\n4. Date\n5. Exit.\nSelect from 1 to 5: ");
            scanf("%d",&n);
        } while (n <1 || n > 5);
        switch (n) {
            case 1 : Frequency(); continue;
            case 2 : Fibonacci(); continue;
            case 3 : Matrix(); continue;
            case 4 : Date(); continue;
            case 5 : return 0;
        }
    } 
}