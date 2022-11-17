#include<stdio.h>
void print__1(int n) {
    for (int i = 0; i < n; i ++) printf("*");
    printf("\n");
}
void print__2(int a, int b) {
    for (int i = 0; i < a; i++) printf(" ");
    for (int i = 0 ; i < b*2+1; i++) printf("*");
    printf("\n");
}
void case__1(){
    int n;
    printf("Nhap so dong:");
    scanf("%d",&n);
    for (int i = 0 ; i < n; i++) print__1(i+1);
}
void case__2(){
    int n;
    printf("Nhap so dong:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) print__2(n-i-1,i);
}
int main() {
    while(1) {
        printf("1. In tam giac vuong can\n2. In tam giac can\n3.Thoat\n");
        int a;
        scanf("%d",&a);
        switch(a) {
            case 1 : case__1(); continue;
            case 2 : case__2(); continue;
            case 3 : return 0;
        } 
    }
}