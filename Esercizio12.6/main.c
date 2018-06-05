#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 5

typedef struct listNode{
  int data;
  struct listNode *nextPtr;
}ListNode;

typedef ListNode *ListNodePtr;

void initNode(ListNodePtr *starPtr);
void insertNode(ListNodePtr *startPtr,int value);
void concatenante(ListNodePtr start1,ListNodePtr start2);
void printList(ListNodePtr start);
ListNodePtr merge(ListNodePtr const start1,ListNodePtr const start2);

int main(){
  srand(time(NULL));
  ListNodePtr inizio1;
  ListNodePtr inizio2;
  ListNodePtr risultato;
  int valore;
  initNode(&inizio1);
  initNode(&inizio2);

  printf("Prima Lista: \n");
  for(size_t i=0;i<SIZE;i++){
    valore=rand()%50+1;
    insertNode(&inizio1,valore);
  }
  printList(inizio1);
  printf("%d",inizio1->data);
  printf("\nSeconda Lista: \n");

  for(size_t i=0;i<SIZE;i++){
    valore=rand()%50+1;
    insertNode(&inizio2,valore);
  }
  printList(inizio2);
  printf("%d",inizio2->data);
/*
  risultato=merge(inizio1,inizio2);
  ("Fusione Lista ordinata: \n");
  printList(risultato);
  printf("\nUnione liste:\n");
  concatenante(inizio1,inizio2);
  printList(inizio1);
*/
}

void initNode(ListNodePtr *startPtr){
  *startPtr=NULL;
}

void insertNode(ListNodePtr *startPtr,int value){
  ListNodePtr newPtr=malloc(sizeof(ListNode));
  newPtr->data=value;
  newPtr->nextPtr=NULL;

  if(*startPtr==NULL){
    *startPtr=newPtr;
  }
  else{
    ListNodePtr currentPtr=*startPtr;

    while(currentPtr->nextPtr!=NULL){
      currentPtr=currentPtr->nextPtr;
    }

    currentPtr->nextPtr=newPtr;
  }
}

printList(ListNodePtr start){
  ListNodePtr currentPtr=start;
  while(currentPtr!=NULL){
    printf("%d--> ",currentPtr->data);
    currentPtr=currentPtr->nextPtr;
  }
  printf("NULL\n");
}

void concatenante(ListNodePtr start1,ListNodePtr start2){
  ListNodePtr lista1=start1;
  ListNodePtr lista2=start2;

  while(lista1->nextPtr!=NULL){
    lista1=lista1->nextPtr;
  }

  if(lista1->nextPtr==NULL){
    lista1->nextPtr=lista2;
  }
}

ListNodePtr merge(ListNodePtr start1, ListNodePtr start2){
  ListNodePtr l1, l2, temp,result;

  l1=start1;
  l2=start2;

  temp=malloc(sizeof(ListNode));
  if(temp==NULL)
  return NULL;

  temp->nextPtr=NULL;
  result=temp;

while((l1!=NULL)&&(l2!=NULL)){
  if((l1->data)<=(l2->data)){
    temp->data=l1->data;
    l1=l1->nextPtr;
  }
  else{
    temp->data=l2->data;
    l2=l2->nextPtr;
  }
  temp->nextPtr=malloc(sizeof(ListNode));
  if(temp->nextPtr==NULL){
    puts("Errore");
    return NULL;
  }
  else{
    temp=temp->nextPtr;
    temp->nextPtr=NULL;
  }
}
  if(l1==NULL){
    temp->data=l2->data;
    while((l2->nextPtr)!=NULL){
      temp->nextPtr=malloc(sizeof(ListNode));
      if(temp->nextPtr==NULL){
        puts("Errore");
        return NULL;
      }
      else{
        temp=temp->nextPtr;
        temp->data=l2->data;
        temp->nextPtr=NULL;
      }
    }
  }
  else{
    temp->data=l1->data;
    while(l1->nextPtr!=NULL){
      temp->nextPtr=malloc(sizeof(ListNode));
      if(temp->nextPtr==NULL){
        puts("Errore");
        return NULL;
      }
      else{
        temp=temp->nextPtr;
        temp->data=l1->data;
        temp->nextPtr=NULL;
          }
        }
      }
      return result;
}
