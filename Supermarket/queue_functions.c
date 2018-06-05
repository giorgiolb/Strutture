//#include"item.h"
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

struct cliente{
  int nome;
  int tempoS;
  struct cliente *nextCliente;
};

typedef struct cliente Cliente;
typedef Cliente *ClientePtr;

ClientePtr headPtr;
ClientePtr tailPtr;


void queueInit(){
  headPtr=tailPtr=NULL;
}

int isEmpty(){
  return headPtr==NULL;
}

void enqueue(int item){
  ClientePtr cliente=malloc(sizeof(Cliente));
  cliente->tempoS=rand()%3+1;
  cliente->nome=item;
  cliente->nextCliente=NULL;
  printf("Il cliente %d e' entrato in coda\n",cliente->nome);

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
  printf("Il cliente %d e' uscito dalla lista\n", tempPtr->nome);
  free(tempPtr);

  return valore;
}

void printQueue(){
ClientePtr currentPtr=headPtr;
  if(currentPtr==NULL){
    printf("La lista e' vuota\n");
  }
  else{
    while(currentPtr!=NULL){
      printf("%d--> ",currentPtr->nome);
      currentPtr=currentPtr->nextCliente;
    }
    puts("NULL");
  }
}

int tempoServizio(){
  int servizio=headPtr->tempoS;
  return servizio;
}
