#include <stdio.h>
#include "student.h"

int main() {
    Student student1;
    strcpy(student1.name, "John Doe");
    student1.grade = 90.5;

    Student student2;
    strcpy(student2.name, "Jane Doe");
    student2.grade = 85.0;

    printf("Student 1: %s, Grade: %.1f\n", student1.name, student1.score);
    printf("Student 2: %s, Grade: %.1f\n", student2.name, student2.score);

    return 0;
}
