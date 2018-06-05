#include<stdio.h>
#include<stdlib.h>
#include "item.h"
#include "stack.h"

struct nodo{
  Item valore;
  struct nodo *nextPtr;
};

typedef struct nodo Nodo;
typedef Nodo *NodoPtr;


static NodoPtr top;

void initStack(){
  top=NULL;
}

int isEmpty(){
  return top==NULL;
}

void stackPush(Item item){
  NodoPtr newPtr= malloc(sizeof *newPtr);
  if(newPtr!=NULL){
    newPtr->valore=item;
    newPtr->nextPtr=top;
    top=newPtr;
  }
  else{
    printf("Errore, memoria esaurita");
  }
}

Item stackPop(){

  if(!isEmpty()){
    NodoPtr tempPtr=top;
    Item valore= top->valore;
    top=top->nextPtr;
    free(tempPtr);
    return valore;
  }
  else
  printf("Errore, nodo non eliminato");
}
