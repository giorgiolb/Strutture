#include<stdio.h>
#include<stdlib.h>

#include"stack.h"
#include"item.h"

struct listNode{
    Item item;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

static  ListNodePtr start;

void stackInit(void){
    start= NULL;
}

int stackIsEmpty(void){
    return start==NULL;
}

void stackPush(Item item){
    ListNodePtr nodo=malloc(sizeof *nodo);
    if(nodo !=NULL) {
        nodo->item = item;
        nodo->nextPtr = start;
        start = nodo;
    }
    else printf("Errore");
}

Item stackPop(){
if(start!=NULL){
ListNodePtr temp=start;
Item item=start->item;
start=start->nextPtr;
free(temp);
return item;
}
else printf("Errore");
}

