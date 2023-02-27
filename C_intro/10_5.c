#include<stdio.h>
int count(int * arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i ++) {
        if (arr[i] == 0) count ++;
    }
    return count;
}
int count_sub(int * arr, int size) {
    int max = 0;
    int count = 0;
    for (int i = 0; i < size ; i ++) {
        if (arr[i] == 0) count ++;
        else {
            if (count > max) max = count;
            count = 0;
        }
    }
    return max;
}
int main() {
    int n;
    printf("Nhap n: ");scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i ++) {
        scanf("%d", &arr[i]);
    }

}