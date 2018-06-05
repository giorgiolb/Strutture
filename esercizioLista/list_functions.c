#include"item.h"
#include"list.h"
#include<stdio.h>
#include<stdlib.h>

struct node{
  Item data;
  struct node *nodePtr;
};

typedef struct node Node;
typedef Node *NodePtr;

static NodePtr startPtr;

void initList(){
  startPtr=NULL;
}

int listIsEmpty(){
  return startPtr==NULL;
}

void insertList(Item item){
  NodePtr newPtr= malloc(sizeof(Node));
  newPtr->data=item;
  newPtr->nodePtr=NULL;
  if(listIsEmpty()){
    startPtr=newPtr;
  }else{
  NodePtr currentPtr=startPtr;

  while(currentPtr->nodePtr!=NULL){
    currentPtr=currentPtr->nodePtr;
  }
  currentPtr->nodePtr=newPtr;
}
}

void printList(){
  NodePtr currentPtr=startPtr;
  while(currentPtr!=NULL){
    printf(" %d -->",currentPtr->data);
    currentPtr=currentPtr->nodePtr;
  }
  printf(" NULL\n");
}
