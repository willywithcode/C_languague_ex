#include<stdio.h>
#include<string.h>

int main() {
    char str[100];
    char substr[50];
    int boolean = 1;
    fgets(str,100,stdin);
    str[strlen(str) - 1] = '\0';
    fgets(substr,50,stdin);
    substr[strlen(substr) - 1] = '\0';
    for (int i = strlen(substr) - 1; i >= 0; i --) {
        if (str[strlen(str) - 1 -(strlen(substr) - 1 -i)] != substr[i]) {
            boolean = 0;
            break;
        }
    }
    printf("%d\n", boolean);
}