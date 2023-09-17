#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 struct TreeNode {
      int val;
      struct TreeNode *left;   // esquerda ==> menores
      struct TreeNode *right;   // direita ==> maiores
  };

typedef struct TreeNode TreeNode;
void imprime(TreeNode *p);
TreeNode* insere(TreeNode *p, int dado);
bool hasPathSum(struct TreeNode* root, int targetSum);
bool conta(struct TreeNode* root, int targetSum, int cont);

int main()
{
    TreeNode *p = NULL;
    
    p = insere(p, 2);
    p = insere(p, 1);
    p = insere(p, 3);

    imprime(p);
    bool teste = hasPathSum(p, 7);

    if(teste == true)
            printf("VERDADEIRO!");
    else
        printf("FALSO!");

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

bool conta(struct TreeNode* root, int targetSum, int cont) {
    if (root == NULL)
        return false;

    else if (root != NULL)
        cont = cont + root->val;
    
    if (root->right == NULL && root->left == NULL && targetSum == cont)
        return true;
    
    return conta(root->left, targetSum, cont) || conta(root->right, targetSum, cont);
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root == NULL)
        return false;

    return conta(root, targetSum, 0);
}