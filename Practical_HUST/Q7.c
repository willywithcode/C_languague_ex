#include<stdio.h>
int main () {
    int n ; 
    do {
        printf("Nhap n: \n");
        scanf("%d", &n);
    } while(n < 5 && n > 20 && n%2 == 0);
    int first = n /2 - 2;
    char input[n];
    printf("Nhap day: ");
    scanf("%s", input);
    for (int i = 0; i < 5; i ++) {
        printf("%c", input[i + first]);
    }
    printf("\n");
}