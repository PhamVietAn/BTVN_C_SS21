#include <stdio.h>

int main(){
    FILE *fptr;
    fptr = fopen("bt05.txt", "w");
    if(fptr == NULL){
        printf("Loi mo tep!\n");
        return 1;
    }

    int n;
    printf("Nhap vao so dong muon nhap: ");
    scanf("%d", &n);
    getchar();

    char text[50];
    for(int i=0; i<n; i++){
        printf("Nhap dong thu %d: ",i+1);
        fgets(text,sizeof(text),stdin);
        fprintf(fptr, "%s", text);
    }
    fclose(fptr);

    fptr = fopen("bt05.txt","r");

    printf("\nNoi dung trong file:\n"); 
    char line[50];
    int lineNumber=1;
    while(fgets(line, sizeof(line), fptr) != NULL){ 
        printf("dong thu %d: %s",lineNumber, line); 
        lineNumber++;
    }

    fclose(fptr);

    return 0;
}