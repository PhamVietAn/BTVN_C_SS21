#include <stdio.h>
#include <string.h>

struct Student {
    char id[20];
    char name[50];
    int age;
};

int main() {
    FILE *fptr;
    struct Student students[100];
    int count = 0;

    fptr = fopen("students.txt", "r");
    if (fptr == NULL) {
        printf("Loi mo tep!\n");
        return 1;
    }

    while (fscanf(fptr, "%s %[^\n] %d\n", students[count].id, students[count].name, &students[count].age) != EOF) {
        count++;
    }

    fclose(fptr);

    printf("Danh sach sinh vien doc tu file:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %s, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
    }

    return 0;
}
