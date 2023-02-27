#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long StringToLong(char input[], int n) {
    long result = 0;
    int power =n;
    for (int i =0; i < n+1; i ++) {
        result += (input[i] - '0') * pow(10,power);
        power --;
    }
    return result;
}
void Matrix() {
    int n;
    printf("Nhap chieu rong ma tran: ");
    scanf("%d",&n);
    int matrix[n][n];
    int check = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            printf("\nmatrix[%d][%d] = ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
    for (int i = 0 ;i < n; i ++) {
        for (int j = 0; j <n ; j ++) {
            if (j != i && matrix[i][j] != 0) check = 1;
            if(j == i && matrix[i][j] != 1) check =1;
        }
    }
    if (check == 1) {
        printf("Khong phai ma tran don vi\n");
    }
    else {
        printf("La ma tran don vi\n");
    }

}
void VeDong(int n, int e) {
    for (int i = 0; i < e; i ++) {
        printf(" ");
    }
    for (int i = 0; i < (2*(n-e) -1); i ++) printf("*");
    for (int i = 0; i < e; i ++) {
        printf(" ");
    }
    printf("\n");
}
void VeHinh() {
    int n;
    char c;
    printf("Nhap so hang n: ");scanf("%d",&n);
    printf("Nhap N hoac X: ");
    scanf(" %c",&c);
    if (c == 'N') {
        for (int i = 0 ; i < n; i ++) {
            VeDong(n,i);
        }
    }
    if (c == 'X') {
        for (int i = 0; i < n; i ++) {
            VeDong(n,n-i-1);
        }
    }
}
void ChuyenSo() {
    char c[100], temp[100];
    printf("Nhap so dien thoai: ");
    scanf("%s",c);
    if (c[0] == '0')
    {
        for (int i = 0; i < strlen(c); i ++) {
            c[i] = c[i+1];
        }
        c[strlen(c)] = '\0';
    }
    // printf("%ld\n",strlen(c));
    if (strlen(c) == 10) for(int i = 0 ;i< 10; i ++) temp[i] = c[i];
    else if(strlen(c) >= 11) for(int i = 0 ;i< 11; i ++) temp[i] = c[i];
    long sdtcu ;
    // printf("%ld\n",strlen(temp));
    if (strlen(temp) == 10) sdtcu = StringToLong(temp,9);
    if (strlen(temp) == 11) sdtcu = StringToLong(temp,10);
    // printf("%s\n",temp);
    // printf("%ld\n",sdtcu);
    printf("So moi: ");
    if ( 16900000000 <= sdtcu && sdtcu <= 16999999999){
        printf("%ld\n", sdtcu - 16900000000 + 3900000000);

    }
    else if ( 16800000000 <= sdtcu && sdtcu <= 16899999999){
        printf("%ld\n", sdtcu - 16800000000 + 3800000000);

    }
    else if ( 16700000000 <= sdtcu && sdtcu <= 16799999999){
        printf("%ld\n", sdtcu - 16700000000 + 3700000000);

    }
    else if ( 16600000000 <= sdtcu && sdtcu <= 16699999999){
        printf("%ld\n", sdtcu - 16600000000 + 3600000000);

    }
    else if ( 16500000000 <= sdtcu && sdtcu <= 16599999999){
        printf("%ld\n", sdtcu - 16500000000 + 3500000000);

    }
    else if ( 16400000000 <= sdtcu && sdtcu <= 16499999999){
       printf("%ld\n", sdtcu - 16400000000 + 3400000000);

    }
    else if ( 16300000000 <= sdtcu && sdtcu <= 16399999999){
        printf("%ld\n", sdtcu - 16300000000 + 3300000000);

    }
    else if ( 16200000000 <= sdtcu && sdtcu <= 16299999999){
        printf("%ld\n", sdtcu - 16200000000 + 3200000000);

    }
    else if ( 16200000000 > sdtcu && sdtcu >= 10000000000 || 17000000000 <= sdtcu && sdtcu <= 999999999999){
        printf("%ld\n", sdtcu);
    }
    else if ( 100000000000 <= sdtcu && sdtcu <= 999999999999){
        printf("khac nha mang\n");
    }
}

void CheckBit() {
    char c[100];
    printf("Nhap so: ");
    scanf("%s",c);
    int So;
    printf("Nhap so: ");
    scanf("%d", &So);
    int index = -1, count = 0, min = 999;
    for (int i = 0; i < strlen(c); i++) {
        if (c[i] == '0') count ++;
        else {
            if (count >= So && count < min) {
                min = count;
                index = i - count;
            }
            count = 0;
        }
    }
    if (index != -1) {
        for (int i = index; i < (index + min); i ++) {
           c[i] = '1';
        }
    }
    printf("%d\n", index);
    printf("%s\n", c);
}
int main() {
    int n;
    while(1) {
        do {
            printf("Chon tu 1 den 5:\n1. Ma tran. \n2. Tam giac.\n3. Chuyen so.\n4. Ban do bit.\n5. Exit.\nChon so: ");
            scanf("%d",&n);
        } while (n <1 || n > 5);
        switch (n) {
            case 1 : Matrix(); continue;
            case 2 : VeHinh(); continue;
            case 3 : ChuyenSo(); continue;
            case 4 : CheckBit(); continue;
            case 5 : return 0;
        }
    } 
}