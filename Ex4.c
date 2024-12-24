#include <stdio.h>

int main(){
    FILE *fptr;
    fptr = fopen("bt01.txt", "r");
    if(fptr == NULL){
        printf("Loi mo tep!\n");
        return 1;
    }

    char firstLine[50];
    
    if(fgets(firstLine, sizeof(firstLine), fptr)!=NULL){
        printf("Dong dau tien trong file: %s\n", firstLine);
    }else{
        printf("File rong.\n");
    }

    fclose(fptr);

    return 0;
}
