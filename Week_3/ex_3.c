#include<stdio.h>
// Write a program print out the multiplication table
int main(void) {
    int m = 1; 
    int n = 1;
    printf("-------------------------BANG CUU CHUONG---------------------------------\n");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < 3; i ++) {
        for(int j = 0; j < 9; j++) {
            for (int k = 0 ; k < 3; k++) {
                printf("|\t %d x %d = %d\t",n, m ,m*n);
                n ++;
            }
            printf("|\n");
            n -= 3;
            m++;
        }
        printf("-------------------------------------------------------------------------\n");
        m =1;
        n += 3;
    }

    return 0;
}