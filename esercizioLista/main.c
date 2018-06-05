#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"list.h"

#define SIZE 20
int main(){
  Item valore;
  srand(time(NULL));
  for(size_t i=0;i<SIZE;i++){
    valore=rand()%50+1;
    insertList(valore);
  }
  printf("La lista e': \n");
  printList();
  //merge();
  //printf("La lista ordinata e':\n");
  //printList();
}
