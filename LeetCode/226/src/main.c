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

int main(int argc, char const *argv[])
{
    printf("Hello World!\n");

    return 0;
}


struct TreeNode* invertTree(struct TreeNode* root){
    struct *aux;
    if (root == NULL)
        return NULL;
    
    aux = root->left;
    root->left = root->right;
    root->left = aux;

    invertTree(root->left);
    invertTree(root->right);

    return root;
    
}

/*
TreeNode* cria(){
    TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode));
    p->val = 0;
    p->left = NULL;
    p->right = NULL;
    
    return p;
}

void pesquisa(TreeNode *p, int dado){
    
    if (p->val == 0)
    {
        insere(p, dado);

    }else if(p->val < dado ){
        if(p->left == NULL ){
            insere(p->left, dado); 
        }else{
            pesquisa(p->left, dado);
        }

    } else if( p->val > dado ){
        if(p->right == NULL ){
            insere(p->right, dado); 
        }else{
            pesquisa(p->right, dado);
        }
    }
    
}

void insere( TreeNode *p, int dado ){
    if(p!=NULL){
        p->val = dado;
        p->left = NULL;
        p->right = NULL;
    }else{
        TreeNode *nova = (TreeNode*)malloc(sizeof(TreeNode));
        p->val = dado;
        p->left = NULL;
        p->right = NULL;
    }
}

void imprime(TreeNode *p, ){
    while (1)
    {
        /* code */
    }
    
}

*/