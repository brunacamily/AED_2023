/*

                    NÃO CONCLUIDO

Dado o formato rootde uma árvore binária, achate a árvore em uma "lista vinculada":

A "lista vinculada" deve usar a mesma Tree struct TreeNodeclasse onde o right ponteiro filho aponta para o próximo nó da lista e 
o left ponteiro filho é sempre null.
A "lista vinculada" deve estar na mesma ordem que uma travessia de pré-ordem da árvore binária.
*/

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

void imprime_ordem_central( struct TreeNode *p);
void Zera (  struct TreeNode *p );
struct TreeNode* insere( struct TreeNode *p, int dado);
void flatten(struct TreeNode* root);
struct TreeNode* insereEsq(struct TreeNode* antiga, struct TreeNode *p);

int main()
{
    struct TreeNode *a=NULL;
    a = insere(a, 10);
    a = insere(a, 7);
    a = insere(a, 20);
    a = insere(a, 3);
    a = insere(a, 8);
    a = insere(a, 120);

    imprime_ordem_central(a);

    printf("\nteste\n");
    flatten(a);
     imprime_ordem_central(a);
    return 0;
}

struct TreeNode* insere( struct TreeNode *p, int dado){
    if (p == NULL)
    {
        struct TreeNode *a = ( struct TreeNode*)malloc(sizeof( struct TreeNode));
        a->val = dado;
        a->left = NULL;
        a->right = NULL;
        return a;
    }else {
        if(dado < p->val)
            p->left = insere(p->left,dado);
        else if(dado > p->val)
            p->right = insere(p->right,dado);
        else
            printf("\n\tERRO : O registro %d ja existe!\n", dado);
        return p;        
    }
}

void imprime_ordem_central( struct TreeNode *p) {
    if(p != NULL){
        imprime_ordem_central(p->left);
        printf(" %d ", p->val);
        imprime_ordem_central(p->right);
    }else{
    printf(" NULL ");
    }
}


void Zera (  struct TreeNode *p ) {
    if ( p->left == NULL && p->right == NULL)
    {  
        free ( p );
    }else{
        if ( p->left != NULL )
            Zera ( p->left );
        if ( p->right != NULL )
            Zera ( p->right );
    }
}



/*
struct TreeNode* insereEsq(struct TreeNode* antiga, struct TreeNode *p){
    if (antiga != NULL && p==NULL)
    {
        struct TreeNode *a = ( struct TreeNode*)malloc(sizeof( struct TreeNode));
        a->val = antiga->val;
        a->left = NULL;
        a->right = NULL;
        p=a;
       
        insereEsq(antiga->left, p);
        insereEsq(antiga->right, p);
        return p;

    }else if( antiga != NULL && p != NULL ){
        struct TreeNode *a = ( struct TreeNode*)malloc(sizeof( struct TreeNode));
        a->val = antiga->val;
        a->left = NULL;
        a->right = NULL;
        p->right=a;
        insereEsq(antiga->left, p->right);
        insereEsq(antiga->right, p->right);
    }
    else
        printf("\nERRO\n");
}

struct TreeNode* insereDir(struct TreeNode* antiga, struct TreeNode *p, int *c){
    if (antiga != NULL && p != NULL && *c == 0)
    {
        *c=1;
        insereDir(antiga->right, p->right, c);
        return p;
    }else if( antiga != NULL && p != NULL && p->right == NULL ){
        struct TreeNode *a = ( struct TreeNode*)malloc(sizeof( struct TreeNode));
        a->val = antiga->val;
        a->left = NULL;
        a->right = NULL;
        p->right=a;
        insereDir(antiga->left, p->right, c);
        insereDir(antiga->right, p->right, c);
    }
    else if(p->right != NULL)
        insereDir(antiga, p->right, c);
    else
        printf("\nERRO\n");

}

void flatten(struct TreeNode* root){
    struct TreeNode *nova=NULL;
    int *i, c=0;
    i=&c;

    nova = insereEsq( root, nova);

    nova = insereDir(root, nova, i);
    Zera(root);
    free(root);
    root=nova;
}

*/
