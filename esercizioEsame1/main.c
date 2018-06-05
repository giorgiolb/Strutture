#include<stdio.h>
#include<stdlib.h>

typedef struct arco{
  size_t nodo;
  struct arco *arcoPtr;
}Arco;

typedef Arco ArcoPtr;

int insertNode(char valore);
int main(){
  FILE *pf;
  ArcoPtr *v;
  int cont=0;

  pf=fopen("archi.txt","r");
  char valore;
    while(!feof(pf)){
      fscanf(pf,"%c",&valore);
      if(valore=='\n')
      cont++;
    }
  cont--;
  v=malloc((cont*cont)sizeof(ArcoPtr));
  while(!feof(pf)){
    fscanf(pf,"%c ",&valore);
    insertNode(valore);
  }

}

void insertNode(){
  //v=(char **)malloc(16*sizeof(char*))
  char a,b;
  int i=0
  while(!feof(pf)){
    fscanf(pf,"%c ",&a);

    while (b!='\n'){
    fscanf(pf,"%c ",&b);

    if((b!=' ') && (b!='\n')){
      v[i]=malloc(sizeof(Arco));
      v[i]->nodo=a;
      v[i]->arcoPtr=malloc(sizeof(Arco));
      (v[i]->arcoPtr)->nodo=b;
      (v[i]->arcoPtr)->arcoPtr=NULL;
      i++;
    }
  }
  }

}
