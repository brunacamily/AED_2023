#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
      int val;
      struct TreeNode *left;   // esquerda ==> menores
      struct TreeNode *right;   // direita ==> maiores
  };

typedef struct TreeNode TreeNode;

int minDepth(struct TreeNode* t){
    int dir,esq;

    if(t == NULL)
        return 0;

    if(t->left == NULL && t->right == NULL)
        return 1;

    if(t->left == NULL) 
        return 1+ minDepth(t->right);


    if(t->right == NULL)
        return 1+ minDepth(t->left);

    esq = minDepth(t->left);
    dir = minDepth(t->right);

    if(dir > esq)
        return esq+1;
    return dir+1;
}

TreeNode* insere(TreeNode *p, int dado){
    if (p == NULL)
    {
        TreeNode *a = (TreeNode*)malloc(sizeof(TreeNode));
        a->val = dado;
        a->left  = NULL;
        a->right = NULL;
        return a;
    }else {
        if(dado < p->val)
            p->left = insere(p->left,dado);
        else 
            p->right = insere(p->right,dado);
        return p;        
    }

}

void imprime(TreeNode *p){
    if (p != NULL)
    {
        printf(" %d ", p->val);
        imprime(p->left);
        imprime(p->right);
    }

    return;
}

int main( )
{
    TreeNode *p = NULL;
    int profMinima = 0;
    
    p = insere(p, 3);
    p = insere(p, 9);
    p = insere(p, 20);
    p = insere(p, 15);
    p = insere(p, 7);
    p = insere(p, 2);

    imprime(p);

    printf("\n");

    profMinima = minDepth(p);

    printf("\nteste: %d", profMinima);

    return 0;
}