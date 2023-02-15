#include <stdio.h>

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int a[n];
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int sumLeft = 0, sumRight = 0;
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {
            sumLeft += a[j];
        }
        for (int j = i + 1; j < n; j++) {
            sumRight += a[j];
        }

        if (sumLeft == sumRight) {
            printf("YES\n");
            return 0;
        }

        sumLeft = 0;
        sumRight = 0;
    }

    printf("NO\n");
    return 0;
}
