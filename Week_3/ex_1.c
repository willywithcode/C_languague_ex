#include<stdio.h>
// Question 1
// Write a program that does the following steps:
// 1.Accept an integer n > 0 from keyboard (does not need to check input) (1 mark)
// 2.Calculate F1(n) = n!(1 mark)
// 3.Calculate (2mark)
// 4.Enter an integer m >1(does not need to check input) (1 mark)
// 5.Calculate(1marks)
int F1(int n) {
    if (n == 1) return 1;
    else return n*F1(n-1);
}
int F2(int n) {
    if (n == 1) return 1;
    else return (n+F2(n-1));
}
int result(int n, int m) {
    if (m ==1) return n;
    else return n*result(n,m-1);
}
int main() {
    int n =0,m=0;
    do {
        printf("Enter n:");
        scanf("%d",&n);
    } while (n <= 0);
    printf("F1(%d) = %d\n",n, F1(n));
    printf("F2(%d) = %d\n",n,F2(n));
    do {
        printf("Enter m:");
        scanf("%d",&m);
    } while (m <= 0);
    printf("Result = %d\n", result(n,m));
}