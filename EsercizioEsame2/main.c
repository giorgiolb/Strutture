#include<stdio.h>
#include<stdlib.h>

typedef struct listNode{
  int data;
  struct listNode * nextPtr;
  struct listNode * fNextPtr;
}ListNode;

typedef ListNode * ListNodePtr;
ListNodePtr startPtr;
void initList();
void insertList(int val);
void deleteList(int val);
int isEmpty();
void printList();

int main(){

    initList();
    int scelta,valore;

    printf("Inserisci una funzione: ");
    scanf("%d",&scelta);
    while(scelta!=0){
      switch(scelta){
        case 1:
          printf("Inserisci un valore: ");
          scanf("%d",&valore);
          if(valore>=0){
          insertList(valore);
          printList();
        }
        else
          printf("Errore, inserire un valore positivo\n");
          break;

        default:
          printf("Errore, inserire un opzione giusto\n");
        }
        printf("Inserisci una funzione: ");
        scanf("%d",&scelta);
      }

    }

void initList(){
  startPtr=NULL;
}

void insertList(int val){
  ListNodePtr newPtr= malloc(sizeof(ListNode));

  if(startPtr==NULL){
    ListNodePtr newPtr2=malloc(sizeof(ListNode));
    startPtr=newPtr;
    newPtr->data=val;
    newPtr->nextPtr=newPtr2;
    newPtr->fNextPtr=newPtr2;
    newPtr2->data= val;
    newPtr2->nextPtr=NULL;
    newPtr2->fNextPtr=NULL;
  }
  else{
    ListNodePtr previousPtr=NULL;
    ListNodePtr currentPtr=startPtr;
    while(currentPtr->nextPtr!=NULL){
      previousPtr=currentPtr;
      currentPtr=currentPtr->nextPtr;
    }
    if(previousPtr!=NULL){
      previousPtr->nextPtr=newPtr;
      newPtr->nextPtr=currentPtr;
      newPtr->fNextPtr=currentPtr;
      newPtr->data=val;
      currentPtr->data= (newPtr->data) + (currentPtr->data);
    }

  }
}


void printList(){
  ListNodePtr currentPtr=startPtr;
  while(currentPtr!=NULL){
    printf("%d-->",currentPtr->data);
    currentPtr=currentPtr->nextPtr;
  }
  printf("NULL\n");
}
