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

TreeNode* invertTree(struct TreeNode* root){
    struct TreeNode *aux;
    if (root == NULL)
        return NULL;
    
    aux = root->left;
    root->left = root->right;
    root->right = aux;

    invertTree(root->left);
    invertTree(root->right);

    return root;   
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
    
    p = insere(p, 4);
    p = insere(p, 2);
    p = insere(p, 7);

    imprime(p);

    printf("\n");

    p = invertTree(p);

    imprime(p);

    return 0;
}