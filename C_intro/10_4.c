#include<stdio.h>
void sort(int * arr, int size) {
    for (int i = 0 ; i < size;i ++) {
        for (int j = i +1; j < size; j ++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i < size; i ++) printf("%d ", arr[i]);
    printf("\n");
}
void sort_odd(int * arr, int size) {
    for (int i = 0; i < size; i ++) {
        for (int j = i +1; j < size; j ++) {
            if (arr[i] > arr[j] && arr[i] %2 ==1 && arr[j] %2 == 1) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i < size; i ++) printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[10];
    for (int i = 0; i < 10; i ++) {
        printf("arr[%d] = ", i);
        scanf("%d",&arr[i]);
    }
    int n;
    while(1) {
        printf("Chon option: \n1.Sap xep.\n2.Sap xep so le\n3. Thoat\n");
        scanf("%d", &n);
        switch(n) {
            case 1: sort(arr, 10); continue;
            case 2: sort_odd(arr, 10); continue;
            case 3: return 0;
        }
    }
    return 0;
}