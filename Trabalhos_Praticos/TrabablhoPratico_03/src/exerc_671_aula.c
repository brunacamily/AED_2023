#include <stdio.h>
#include <stdlib.h>


 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };


int menor(struct TreeNode* root, int menor, int menor2);
int max(int a, int b);



int main(int argc, char const *argv[])
{
    printf("Hello World!\n");

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
int Fmenor(struct TreeNode* root, int menor, int menor2);
int max(int a, int b);
int min(int a, int b);

int findSecondMinimumValue(struct TreeNode* root){
    if(root == NULL)
        return -1;
    else {
        return Fmenor(root, root->val, max(root->left->val, root->right->val));
    }
}

int max(int a, int b){ 
    if(a < b)
        return b;
    if(a > b)
        return a;
    else 
        return -1;
}

int min(int a, int b){ 
    if(a > b)
        return b;
    if(a < b)
        return a;
    else 
        return -1;
}

int Fmenor(struct TreeNode* root, int menor, int menor2){
    if(root->left != NULL && root->right != NULL){

        if (menor > root->val ){
            menor = root->val;
            return min(Fmenor(root->left, menor, menor2), Fmenor(root->right, menor, menor2));

        }else if(menor2 > root->val){
           menor2 = root->val; 
           return min(Fmenor(root->left, menor, menor2), Fmenor(root->right, menor, menor2));

        }else{
            return min(Fmenor(root->left, menor, menor2), Fmenor(root->right, menor, menor2));;
        }
    }else{
        return menor;
    }
}