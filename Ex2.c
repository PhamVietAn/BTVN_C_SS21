#include <stdio.h>

int main(){
    FILE *fptr;
    fptr = fopen("bt01.txt", "r");
    if(fptr == NULL){
        printf("Loi mo tep!\n");
        return 1;
    }

    char firstChar;
    firstChar = fgetc(fptr);

    if(firstChar != EOF){
        printf("Ky tu dau tien trong file: %c\n", firstChar);
    }else{
        printf("File rong.\n");
    }

    fclose(fptr);

    return 0;
}
