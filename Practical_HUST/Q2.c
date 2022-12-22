#include<stdio.h>
int main() {
    int n;
    do {
        printf("Nhap n: \n");
        scanf("%d",&n);
    } while (n < 0);
    int i =0;
    int sum = 0;
    while (n > 0 && i != 3) {
        if (n %2 ==0){
            sum += n;
            i ++;
        }    
        n --;
    }
    printf("%d\n", sum);
    return 0;
}