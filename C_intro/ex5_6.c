#include<stdio.h>
int main() {
    char name[10];
    printf("Enter your name:");scanf("%s",name);
    printf("%c%s\n",(name[0] <='z' && name[0] >='a' )? name[0] -32 : name[0], name +1);
}