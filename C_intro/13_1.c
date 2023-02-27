#include <stdio.h>
#include<string.h>
int Count(char * str);
int main() {
    char str[100];
    fgets(str,10,stdin);
    
    printf("%d\n", Count(str));
   
}
int Count (char * str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i ++) {
        if (str[i] == ' ') count ++;
    }
    return count;
}