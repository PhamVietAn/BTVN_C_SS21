#include <stdio.h>
#include <string.h>

struct Student{
    char id[20];
    char name[50];
    int age;
};

void displayStudents();

int main(){
    FILE *fptr;
    fptr = fopen("students.txt", "w");
    if(fptr == NULL){
        printf("Loi mo tep!\n");
        return 1;
    }

    int n;
    printf("Nhap vao so luong sinh vien: ");
    scanf("%d", &n);
    getchar();

    struct Student students[n];
    for(int i = 0; i < n; i++){
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);

        printf("ID: ");
        fgets(students[i].id, sizeof(students[i].id), stdin);
        students[i].id[strcspn(students[i].id, "\n")] = '\0';

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        printf("Age: ");
        scanf("%d", &students[i].age);
        getchar();

        fprintf(fptr, "%s\n%s\n%d\n", students[i].id, students[i].name, students[i].age);
    }

    fclose(fptr);

    printf("\nThong tin sinh vien da duoc luu vao tep students.txt.\n");

    displayStudents();

    return 0;
}

void displayStudents(){
    FILE *fptr = fopen("students.txt", "r");
    if(fptr == NULL){
        printf("Loi mo tep!\n");
        return;
    }

    struct Student student;
    printf("\nDanh sach sinh vien:\n");
    while(fgets(student.id, sizeof(student.id), fptr) != NULL){
        student.id[strcspn(student.id, "\n")] = '\0';

        fgets(student.name, sizeof(student.name), fptr);
        student.name[strcspn(student.name, "\n")] = '\0';

        fscanf(fptr, "%d\n", &student.age);

        printf("ID: %s, Name: %s, Age: %d\n", student.id, student.name, student.age);
    }

    fclose(fptr);
}
