#include<stdio.h>
int main() {
    int m,n;
    printf("Input:");
    scanf("%d %d", &m,&n);
    printf("%s\n", (m%2==0 && n%2 ==0) ? "True" : "False");
    return 0;
}