//#include"item.h"
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

struct cliente{
  int tempoS;
  struct cliente *nextCliente;
};

typedef struct cliente Cliente;
typedef Cliente *ClientePtr;

ClientePtr headPtr;
ClientePtr tailPtr;

void queueInit();
void enqueue(int item);
int dequeue();
int isEmpty();
void printQueue();
int tempoServizio();

void queueInit(){
  headPtr=tailPtr=NULL;
}

int isEmpty(){
  return headPtr==NULL;
}

void enqueue(){
  ClientePtr cliente=malloc(sizeof(Cliente));
  cliente->tempoS=rand()3+1;
  cliente->nextCliente=NULL;

  if(isEmpty()){
    headPtr=cliente;
  }
  else
    tailPtr->nextCliente=cliente;

  tailPtr=cliente;
}

int dequeue(){
  int valore=headPtr->tempoS;
  ClientePtr tempPtr=headPtr;
  headPtr=headPtr->nextCliente;

  if(headPtr==NULL){
    tailPtr=NULL;
  }
  free(tempPtr);
  return valore;
}

void printQueue(){
ClientePtr currentPtr=headPtr;
  if(currentPtr==NULL){
    printf("La lista e' vuota");
  }
  else{
    while(currentPtr!=NULL){
      printf("%d--> ",currentPtr->tempoS);
      currentPtr=currentPtr->nextCliente;
    }
    puts("NULL");
  }
}

int tempoServizio(){
  int servizio=headPtr->tempoS;
  return servizio;
}
