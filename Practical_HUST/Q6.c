#include<stdio.h>
#include<string.h>
int main() {
    char ten_nguoi[5][10];
    for (int i = 0; i < 5; i ++) {
        scanf("%s", ten_nguoi[i]);
    }
    for(int i = 0; i < 5; i ++) {
        for (int j = i; j < 5; j ++) {
            char temp[10];
            if (ten_nguoi[i][0] > ten_nguoi[j][0]) {
                strcpy(temp,ten_nguoi[i]);
                strcpy(ten_nguoi[i],ten_nguoi[j]);
                strcpy(ten_nguoi[j],temp);
            }
        }
    }
    for (int i = 0 ; i < 5; i ++) printf("%s ", ten_nguoi[i]);
    printf("\n");
}