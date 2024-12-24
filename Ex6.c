#include <stdio.h>

void displayFile(const char *filename);

int main(){
    FILE *sourceFile, *destFile;

    sourceFile = fopen("bt01.txt", "r");
    if(sourceFile == NULL){
        printf("Loi mo tep nguon!\n");
        return 1;
    }

    destFile = fopen("bt06.txt", "w");
    if(destFile == NULL){
        printf("Loi mo tep dich!\n");
        fclose(sourceFile);
        return 1;
    }
    displayFile("bt06.txt");

    char data;
    while((data = fgetc(sourceFile)) != EOF){
        fputc(data, destFile);
    }

    printf("Sao chep thanh cong noi dung tu bt01.txt sang bt06.txt\n");

    fclose(sourceFile);
    fclose(destFile);

    displayFile("bt06.txt");

    return 0;
}

void displayFile(const char *filename){
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL){
        printf("Loi mo tep %s!\n", filename);
        return;
    }

    char data;
    printf("Noi dung cua tep %s:\n", filename);
    while((data = fgetc(fptr)) != EOF){
        putchar(data);
    }
    printf("\n");

    fclose(fptr);
}
