#include <stdio.h>
#include <stdbool.h>
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
TreeNode* insere(TreeNode *p, int dado);
void imprime(TreeNode *p);
bool testMenor(struct TreeNode* root, int raiz);
bool testMaior(struct TreeNode* root, int raiz);
bool isValidBST(struct TreeNode* root);

int main( )
{
    TreeNode *p = NULL;
    bool teste = false;
    
    p = insere(p, 2);
    p = insere(p, 1);
    p = insere(p, 3);

    imprime(p);
    printf("\n");
    teste = isValidBST(p);

    if(teste == true){
        printf("\nVerdadeiro");
    }else{
        printf("\nFalso");
    }

    return 0;
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

void imprime(TreeNode *p) {
    if (p != NULL)
    {
        printf(" %d ", p->val);
        imprime(p->left);
        imprime(p->right);
    }
    return;
}
bool testMenor(struct TreeNode* root, int raiz){
    if(root == NULL)
        return true;
    else if( root->left != NULL && root->left->val > root->val)
        return false;
    else if( root->right != NULL && root->right->val < root->val)
        return false;
    else if(root->val < raiz)
        return testMenor(root->left, raiz) && testMenor(root->right, raiz);
    else
        return false;
}

bool testMaior(struct TreeNode* root, int raiz){
    if(root == NULL)
        return true;
    else if( root->left != NULL && root->left->val > root->val)
        return false;
    else if( root->right != NULL && root->right->val < root->val)
        return false;
    else if(root->val > raiz)
        return testMaior(root->left, raiz) && testMaior(root->right, raiz);
    else
        return false;
}

bool isValidBST(struct TreeNode* root) {
    return testMenor(root->left, root->val) && testMaior(root->right, root->val);
};