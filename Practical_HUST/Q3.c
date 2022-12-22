#include<stdio.h>
int main() {
    char input__0[4];
    for (int i =0 ; i < 4; i ++) {
        scanf(" %c", &input__0[i]);
    }
    for(int i = 0; i < 4; i ++) {
        for (int j = i; j < 4; j ++) {
            int temp;
            if (input__0[i] > input__0[j]) {
                temp = input__0[i];
                input__0[i] = input__0[j];
                input__0[j] = temp;
            }
        }
    }
    for (int i = 0; i < 4; i ++) printf("%c ", input__0[i]);
    printf("\n");
    return 0;
}