#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM_CLASS 200
int count =0;
typedef struct Class {
    int ClassID;
    char CourseName[30];
    char Room[10];
    int Day;
    char Slots[10];
} Class;
Class Classes[MAX_NUM_CLASS];
void Input_Class(int num_classes) {
    for (int i = 0; i < num_classes; i ++) {
        if (count > MAX_NUM_CLASS) printf("Lop hoc da day.\n");
        else {
            getchar();printf("Nhap Coure Name: "); fgets(Classes[count].CourseName,30,stdin);
            Classes[count].CourseName[strcspn(Classes[count].CourseName, "\n")] = '\0';
            printf("Nhap ClassID: ");scanf("%d",&Classes[count].ClassID);
            getchar();printf("Nhap Room: "); fgets(Classes[count].Room,10,stdin);
            Classes[count].Room[strcspn(Classes[count].Room, "\n")] = '\0'; 
            do {
                printf("Nhap Day: ");scanf("%d",&Classes[count].Day);
            } while (Classes[i].Day < 2 || Classes[i].Day >7);
            int finish,start;
            do {
                getchar();printf("Nhap Slots: ");fgets(Classes[count].Slots,10,stdin);
                Classes[count].Slots[strcspn(Classes[count].Slots, "\n")] = '\0'; 
                start = atoi(Classes[count].Slots);
                if (start >=10) finish = atoi(Classes[count].Slots + 3);
                else finish = atoi(Classes[count].Slots + 2);
            } while (finish < 1 || finish >12 || start < 1 || start >12 || (((start >=10) && Classes[count].Slots[2] != '-'))||((start < 10) && Classes[count].Slots[1]!= '-'));
            count ++;
        }
    }
}
void print_class() {
    printf("%-20s %-20s %-20s %-20s %-20s\n", "Class ID", "Course Name", "Room", "Day", "Slots");
    for (int i = 0; i < count; i++) {
        printf("%-20d %-20s %-20s %-20d %-20s\n", Classes[i].ClassID, Classes[i].CourseName,Classes[i].Room,Classes[i].Day, Classes[i].Slots);
    }
}
void find_class_by_room(char *name) {
    int count_finded_class = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(Classes[i].Room, name) == 0) {
            count_finded_class ++;
        }
    }
    if (count_finded_class ==0) printf("Khong co lop %s trong danh sach.\n",name);
    else {
        printf("Co %d lop:\n ",count_finded_class);
        printf("%-20s %-20s %-20s %-20s %-20s\n", "Class ID", "Course Name", "Room", "Day", "Slots");
        for (int i = 0; i < count; i++) {
            if (strcmp(Classes[i].Room, name) == 0) {
                printf(" %-20d %-20s %-20s %-20d %-20s\n", Classes[i].ClassID, Classes[i].CourseName,Classes[i].Room,Classes[i].Day, Classes[i].Slots);
            }
        }
    }
}
void Sorted_class_by_ID() {
    for (int i = 0; i < count; i ++) {
        for (int j = i + 1; j < count; j ++) {
            if (Classes[j].ClassID < Classes[i].ClassID) {
                int temp_ID;
                char temp_name[30];
                char temp_room[10];
                int temp_day;
                char temp_slots[10];

                temp_ID = Classes[i].ClassID;
                Classes[i].ClassID = Classes[j].ClassID;
                Classes[j].ClassID = temp_ID;

                strcpy(temp_name,Classes[i].CourseName);
                strcpy(Classes[i].CourseName,Classes[j].CourseName);
                strcpy(Classes[j].CourseName,temp_name);

                strcpy(temp_room,Classes[i].Room);
                strcpy(Classes[i].Room,Classes[j].Room);
                strcpy(Classes[j].Room,temp_room);

                temp_day = Classes[i].Day;
                Classes[i].Day = Classes[j].Day;
                Classes[j].Day = temp_day;

                strcpy(temp_slots,Classes[i].Slots);
                strcpy(Classes[i].Slots,Classes[j].Slots);
                strcpy(Classes[j].Slots,temp_slots);
            }
        }
    }
}
void Check_classes() {
    int len = 0;
    for(int i = 0; i < count - 1; i ++) {
        for(int j = i+1; j <count; j++) {
            if (Classes[i].Day == Classes[j].Day && strcmp(Classes[i].Room,Classes[j].Room) == 0) {
                int first_start = atoi(Classes[i].Slots);
                int se_start = atoi(Classes[j].Slots);
                int first_finish;
                int se_finish;
                if (first_start >=10) first_finish = atoi(Classes[i].Slots + 3);
                else first_finish = atoi(Classes[i].Slots + 2);
                if (se_start >=10) se_finish = atoi(Classes[j].Slots + 3);
                else se_finish = atoi(Classes[j].Slots + 2);
                if ((first_start <= se_start && se_start <= first_finish) || (first_start >= se_start && se_finish >= first_start)) {
                    printf("Hai lop %s va %s bi trung\n",Classes[i].CourseName,Classes[j].CourseName);
                    len ++;
                }
            }

        }
    }
    if (len==0) printf("Khong co lop nao bi trung.\n");
}
int main() {
    int choice;
    while(1) {
        do {
            printf("Chon tu 1 den 5\n");
            printf("1. Bo sung lop hoc\n");
            printf("2. In thong tin lop hoc\n");
            printf("3. Tim khiem theo phong\n");
            printf("4. Sap xep\n");
            printf("5. Kiem tra trung phong\n");
            printf("6. Thoat chuong trinh.\n");
            scanf("%d", &choice);
    } while (choice < 1 || choice > 6);
        switch (choice) {
            case 1: 
                int num_class;
               
                do {
                    printf("Nhap so lop can nhap: ");
                    scanf("%d",&num_class);
                }while(num_class < 1);
                Input_Class(num_class);
                continue;
            case 2:
                print_class();continue;
            case 3: 
                char name[10];
                getchar();printf("Nhap ten lop can tim: ");fgets(name,10,stdin);
                name[strcspn(name, "\n")] = '\0'; 
                find_class_by_room(name);
                continue;
            case 4:
                Sorted_class_by_ID();
                print_class();
                continue;
            case 5:     
                Check_classes();
                continue;
            case 6:
                return 0;
        }
    }
} 