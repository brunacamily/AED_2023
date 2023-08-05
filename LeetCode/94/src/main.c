#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
struct TreeNode root;

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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    returnSize = (int*) malloc (sizeof(int));
    returnSize = root->val;
    if( root->left != NULL ){
        inorderTraversal(root, returnSize);
    }else if( root->right != NULL ){
        inorderTraversal(root, returnSize);
    }
    return returnSize;
}
