//#include"item.h"
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TEMPO 60

int main(){
srand(time(NULL));
int a=0;
int b=0;
int controllo=0;
int risultato=0;

for(size_t i=0;i<TEMPO;i++){

  if(a==0){
  a=rand()%3+1;
  }

  if(controllo==a){
    enqueue(a);
    controllo=0;
    a=rand()%3+1;
  }
  else{
    controllo++;
  }
if(!isEmpty()){
  if(b==tempoServizio()){
    risultato = dequeue();
    b=0;
  }
  else{
    b++;
  }
  }
if(i==10){
  printQueue();
}
}

}
