#include<stdio.h>
void first_fun(int * array) {
    int sum = 0;
    for(int i = 0; i < 100; i ++) {
        if (array[i] %2 == 1) sum += array[i];
    } 
    printf("The sum : %d", sum);
}
void second_fun(int *array) {
    int min = array[0];
    for (int i = 0; i < 100; i ++) {
        if (array[i] < min) min = array[i];
    }
    printf("The minimum: %d" , min);
}
int main () {
    int array[100];
    for (int i = 0; i < 100; i ++) scanf("%d", &array[i]);
    int n;
    while (1) {
        printf("Nhap option: \n1. Tim tong cac so le.\n 2. Tim min\n3. Thoat\n");
        scanf("%d", &n);
        switch (n){
            case 1: first_fun(array);continue;
            case 2: second_fun(array);continue;
            case 3: break;
        }
    }
    return 0;
}