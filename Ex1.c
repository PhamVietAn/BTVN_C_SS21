#include <stdio.h>
#include <string.h>


int main(){
    FILE *fptr;
    fptr = fopen("bt01.txt", "w");
    if(fptr == NULL){
        printf("Loi mo tep!\n");
        return 1;
    }

    char text[50];
    printf("ghi chuoi ky tu bat ky vao file: ");
    fgets(text, sizeof(text), stdin);
    // text[strcspn(text, "\n")] = 0;

    fprintf(fptr, "%s", text);
    printf("chuoi sau khi ghi: %s\n", text);

    fclose(fptr);

    return 0;
}
