//      94 - Dado o valor rootde uma árvore binária, retorne o percurso em ordem dos valores de seus nós .


#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
struct TreeNode root;
struct TreeNode* insere(struct TreeNode *p, int val);
void imprime_pos_ordem(struct TreeNode *p);
int* inorderTraversal(struct TreeNode *p, int* returnSize);
void Traversal(struct TreeNode *p, int* returnSize, int* tam);

int main()
{
    int *teste =(int*)malloc(sizeof(int)), j=0;
    teste[0]=1;
    teste =(int*)malloc(sizeof(int));
    teste[1]=2;
    teste =(int*)malloc(sizeof(int));
    teste[2]=3;
    while (!teste)
    {
        j++;
        printf("ola\n");
    }
    
    struct TreeNode * arv=NULL;
    arv = insere(arv, 10);
    arv = insere(arv, 7);
    arv = insere(arv, 20);

    imprime_pos_ordem(arv);
    
    printf("%d", j);
    return 0;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct TreeNode* insere(struct TreeNode *p, int val){
    if (p == NULL)
    {
        struct TreeNode *a = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        a->val = val;
        a->left  = NULL;
        a->right = NULL;
        return a;
    }else {
        if(val < p->val)
            p->left = insere(p->left,val);
        else if(val > p->val)
            p->right = insere(p->right,val);
        else
            printf("\n\tERRO : O registro %d ja existe!\n", val);
        return p;        
    }
}

void imprime_pos_ordem(struct TreeNode *p) {
    if (p != NULL)
    {
        imprime_pos_ordem(p->left);
        imprime_pos_ordem(p->right);
        printf(" %d ", p->val);
    }
    return;
}

//                      funcões enviadas no leetcode abaoxo:

 void Traversal(struct TreeNode *p, int* returnSize, int* tam){ //ordem central
    if (p != NULL)
    {
        Traversal(p->left, returnSize, tam);
        returnSize[(*tam)++] = p->val;
        Traversal(p->right, returnSize, tam);
        
        return  returnSize;
    }
    return 0;
}

int* inorderTraversal(struct TreeNode *p, int* returnSize) {
    *returnSize=0;
    int *tam = (int*) malloc (sizeof(int)*100);
    Traversal(p, tam, returnSize);
    
    return tam;
}