#include<stdio.h>
void print(int a) {
    for (int i = 0; i < (a+1)/2; i++) printf("%c",'A'+i);
    for (int i =0; i < (a-1)/2;i++) printf("%c",'A'-i+(a+1)/2-2);
    printf("\n");
}
int main() {
    int n;
    printf("Mhap so dong : ");
    scanf("%d",&n);
    for (int i =0; i < n; i ++) print(i*2+1);
}
