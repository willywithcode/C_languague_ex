#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

// typedef struct Student {
//     char name[MAX_NAME_LENGTH];
//     int score;
// } Student;

int read_students_from_file(const char *file_name, Student students[]) {
    FILE *file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Error opening file %s.\n", file_name);
        return 0;
    }

    int count = 0;
    while (fread(&students[count], sizeof(Student), 1, file) == 1) {
        count++;
        if (count == MAX_STUDENTS) {
            break;
        }
    }

    fclose(file);
    return count;
}

void write_students_to_file(const char *file_name, Student students[], int count) {
    FILE *file = fopen(file_name, "wb");
    if (file == NULL) {
        printf("Error opening file %s.\n", file_name);
        return;
    }

    for (int i = 0; i < count; i++) {
        fwrite(&students[i], sizeof(Student), 1, file);
    }

    fclose(file);
}

void print_students(Student students[], int count) {
    printf("%-20s %-20s\n", "Name", "Score");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-20d\n", students[i].name, students[i].score);
    }
}

int find_student_by_name(Student students[], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    const char *file_name = "Sv2023.dat";
    Student students[MAX_STUDENTS];
    int count = read_students_from_file(file_name, students);

    int choice;
    do {
        printf("Student Management Program\n");
        printf("1. View students\n");
        printf("2. Add student\n");
        printf("3. Find student by name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_students(students, count);
                break;
            case 2:
                getchar();
                printf("Enter student name: ");
                fgets(students[count].name, MAX_NAME_LENGTH, stdin);
                students[count].name[strcspn(students[count].name, "\n")] = '\0'; 
                printf("Enter student score: ");
                scanf("%d", &students[count].score);
                count++;
                write_students_to_file(file_name, students, count);
                break;

            case 3:
                char name[MAX_NAME_LENGTH];
                getchar();
                printf("Enter student name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; 
                printf("%s\t", students[find_student_by_name(students,count,name)].name);
                printf("%d\n", students[find_student_by_name(students,count,name)].score);
                break;
            case 4:
                return 0;
        }
    } while (choice < 1 || choice > 4);
} 
