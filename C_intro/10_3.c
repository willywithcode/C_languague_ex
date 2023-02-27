#include<stdio.h>
int check_equallity(int * arr1, int * arr2, int size) {
    for (int i = 0; i < size; i ++) {
        if (arr1[i] != arr2[i]) return 0;
    }
    return 1;
}
int main() {
    int arr1[3] = {1,2,3};
    int arr2[3] = {1,2,3};
    printf("%d\n", check_equallity(arr1,arr2,3));
}