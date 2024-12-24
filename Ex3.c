#include <stdio.h>
#include <string.h>

int main(){
    FILE *fptr;
    fptr = fopen("bt01.txt", "a");
    if(fptr == NULL){
        printf("Loi mo tep!\n");
        return 1;
    }

    char text[50];
    printf("Nhap chuoi ky tu can ghi them vao file: ");
    fgets(text, sizeof(text), stdin);
    // text[strcspn(text, "\n")] = 0;
    fprintf(fptr, "%s", text);

    printf("Chuoi da duoc ghi them vao file\n", text);

    fclose(fptr);

    fptr = fopen("bt01.txt", "r");
    
    printf("Noi dung trong file:\n"); 
    char ch;
    while((ch = fgetc(fptr)) != EOF){ 
        putchar(ch); 
    }

    fclose(fptr);

    printf("\n");

    return 0;
}
