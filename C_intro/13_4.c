#include<stdio.h>
#include<string.h>
void My_Strcpy(char *sour, char *des);
int main() {
    char sour[10] = "hello1234";
    char des[10];
    My_Strcpy(sour,des);
    printf("%s\n",des);
}
void My_Strcpy(char *sour, char *des) {
    for (int i = 0; i < strlen(sour); i ++) {
        *(des +i) = *(sour +i);
    }
}