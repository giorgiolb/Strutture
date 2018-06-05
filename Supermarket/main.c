//#include"item.h"
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TEMPO 60

int main(){
srand(time(NULL));
int a=rand()%3+1;
int b=0;
int controllo=0;
int risultato=0;
int nome=1;

for(size_t i=0;i<TEMPO;i++){
printf("Minuto %d:",i);
  if(controllo==a){
    enqueue(nome);
    nome++;
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
if((i>0)&&(i%10==0)){
  printQueue();
}
puts("\n");
}

}
