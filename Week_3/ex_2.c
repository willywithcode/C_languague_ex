#include<stdio.h>
#include<math.h>
// Implement functions with the following prototypes:
// int fun(int n);
// Function returns 1 if n is a prime number, therwise return 0. (3 marks)
// Example: fun(1)  = 0
// fun(2)  = 1
// fun(5)  = 1
// fun(6)  = 0
// S(n) = 1 + 2 + 3 +...+ n;
// int foo(int c);
// Your function returns the highest integer n so thats(n) <= c (1 mark)
int fun(int n) {
    if (n == 0) return 0;
    else {
        int count = 0;
        for (int i = 1; i < pow(n,0.5);i ++) {
            if (n %i == 0) count ++;
        }
        if (count == 1) return 1;
        else return 0;
    }
}
int F2(int n) {
    if (n == 1) return 1;
    else return (n+F2(n-1));
}
int foo(int n) {
    int i = 1;
    while (F2(i) <= n) {
        i ++;
    }
    return i -1;
}
int main() {
    printf("fun(1) = %d\n", fun(1));
    printf("fun(2) = %d\n", fun(2));
    printf("fun(5) = %d\n", fun(5));
    printf("fun(6) = %d\n", fun(6));
    printf("\n");
    printf("foo(9) = %d\n", foo(9));
    printf("foo(10) = %d\n", foo(10));
    printf("foo(11) = %d\n", foo(11));
}