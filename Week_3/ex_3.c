#include<stdio.h>
// Write a program print out the multiplication table
int main(void) {
    int m = 1, n = 1;
    printf("-------------------------BANG CUU CHUONG---------------------------------\n");
    printf("-------------------------------------------------------------------------\n");
    while (1){
        while (1){
            printf("|\t%d x %d = %d\t", n, m, n * m);
            if (n % 3 == 0){
                m++;
                n -=3;
                printf("|\n");
            };
            n++;
            if (m == 10) {
                m = 1;
                n +=3;
                break;
            }
        }
        printf("-------------------------------------------------------------------------\n");
        if (n == 10) {
            break;
        }
    }
    return 0;
}