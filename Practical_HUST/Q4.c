#include<stdio.h>
int main() {
    int input__0[7];
    for (int i =0 ; i < 7; i ++) {
        scanf("%d", &input__0[i]);
    }
    for(int i = 0; i < 7; i ++) {
        for (int j = i; j < 7; j ++) {
            int temp;
            if (input__0[i] > input__0[j]) {
                temp = input__0[i];
                input__0[i] = input__0[j];
                input__0[j] = temp;
            }
        }
    }
    for (int i = 0; i < 7; i ++) printf("%d ", input__0[i]);
    printf("\n");
    return 0;
}