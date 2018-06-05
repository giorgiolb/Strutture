#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"item.h"
#include"stack.h"

int main(int argc, char *argv[]){

    char stringa[60];
    printf("Inserisci una stringa: ");
    gets(stringa);
    int N=strlen(stringa);

    stackInit();

    for(size_t i=0; stringa[i]!='\0';i++){
        stackPush(stringa[i]);
    }
    printf("\n");
    while (!stackIsEmpty()){
        printf("%c",stackPop());
    }
printf("\n SAS\nSIS\n");
return 0;
}
