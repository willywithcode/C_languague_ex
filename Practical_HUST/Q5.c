#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for (int j = 0; j < n;j ++) scanf("%d", &array[j]);
    int i = 0;
    for (i = 0;i < n/2 ; i ++) {
        if (array[i] != array[n-i-1]) {
            printf("asymetric\n");
            break;
        }
        else continue;
    }
    if (i == n /2) printf("symetric\n"); 

}