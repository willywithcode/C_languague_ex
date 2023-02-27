#include <stdio.h>
#include <string.h>
#include<ctype.h>
int Check (char * str) {
    int boolean = 1;
    if (strlen(str) != 7) boolean = 0;
    else {
        for (int i = 0; i < 7; i ++) {
            if (i >=0 && i <3 && !(isalpha(str[i]))) {
                boolean = 0;
                break;
            } 
            if (i >=3 && i < 7 && !(isdigit(str[i]))) {
                boolean = 0;
                break;
            }
        }
    }
    return boolean;
}
int main() {
    char str[10];
    // scanf("%s",str);
    fgets(str,10,stdin);str[strlen(str)-1] = '\0';
    int i, count;
    i = count = 0;
    // while (str[i] != '\0')
    // {
    //     i ++;
    // }
    printf("%ld",strlen(str));
    // printf("%d\n",Check(str));
}