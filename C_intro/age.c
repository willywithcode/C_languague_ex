#include <stdio.h>
#include<math.h>
int main() {
	float diem;
	printf("Nhap diem: ");
	scanf("%f",&diem);
	diem = (round(diem * 10))/100;
	if (diem >= 0 && diem <= 3.9) printf("F 0");
	else if (diem >= 4.0 && diem <= 4.9) printf("D 1\n");
	else if (diem >= 5.0 && diem <= 5.4) printf("D+ 1.5\n");
	else if (diem >= 5.5 && diem <= 6.4) printf("C 2\n");
	else if (diem >= 6.5 && diem <= 6.9) printf("C+ 2.5\n");
	else if (diem >= 7.0 && diem <= 7.9) printf("B 3\n");
	else if (diem >= 8.0 && diem <= 8.4) printf("B+ 3.5\n");
	else if (diem >= 8.5 && diem <= 9.4) printf("A 4\n");
	else if (diem >= 9.5 && diem <= 10.0) printf("A+ 4\n");
	
	return 0;	
}
