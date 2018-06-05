#include<stdio.h>
#include<stdlib.h>
#include"item.h"
#include"tree.h"
#include<time.h>

struct treeNode{
struct treeNode *left;
Item id;
Item saldo;
struct treeNode *right;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

static TreeNodePtr root;

void treeInit(){
root=NULL;
}

int treeIsEmpty(){
return root==NULL;
}

void treeInsertNode(Item id){
Item nuovoId=id;
TreeNodePtr nodo= malloc(sizeof *nodo);

if (treeIsEmpty()){
nodo->id=id;
nodo.>saldo =rand()%100;
nodo->left=NULL;
nodo->right=NULL;
root=nodo;
}

if(nuovoId < root->id){



