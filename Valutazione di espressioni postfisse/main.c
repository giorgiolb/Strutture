#include<stdio.h>
#include<stdlib.h>
#include"item.h"
#include"stack.h"

int main(){
  char stringa[50];
  int N;

  printf("Inserisci una stringa: ");
  gets(stringa);
  puts(stringa);

  initStack();

  for(size_t i=0;stringa[i]!='\0';i++){


    if(stringa[i]=='+')
    stackPush(stackPop()+stackPop());

    if (stringa[i]=='*')
    stackPush(stackPop()*stackPop());

    if(stringa[i]>='0' && stringa[i]<='9')
    stackPush(0);

    while(stringa[i]>='0' && stringa[i]<='9')
    stackPush(10*stackPop()+stringa[i++]-'0');

  }
  printf("Il risultato e' : %d \n",stackPop());
}
