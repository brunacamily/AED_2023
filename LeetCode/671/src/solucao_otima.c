#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 struct TreeNode {
      int val;
      struct TreeNode *left;   // esquerda 
      struct TreeNode *right;   // direita 
  };

typedef struct TreeNode TreeNode;
int findSecondMinimumValue ( struct TreeNode* root );
TreeNode* insere ( TreeNode *p, int dado );
void imprime ( TreeNode *p );

int main( )
{ 
    TreeNode *p = ( TreeNode * ) malloc ( sizeof( TreeNode ) ) ;

    TreeNode *p1 = ( TreeNode * ) malloc ( sizeof( TreeNode ) ) ;
    p1->val = 2;
    p1->left = NULL;
    p1->right = NULL;

    TreeNode *p2 = ( TreeNode * ) malloc ( sizeof( TreeNode ) ) ;
    p2->val = 3;
    p2->left = NULL;
    p2->right = NULL;
    
    p->val = 2;
    p->left = p1; 
    p->right = p2;

    imprime( p );

    int teste;
    teste = findSecondMinimumValue( p );

    printf( " \nTESTE:%d ", teste );

    return 0;
}

int fmenor ( struct TreeNode* root, int val ) {
    if ( root == NULL )
        return -1;
    if ( root->val != val )
        return root->val;
        
    int m1 = fmenor ( root->left, val );
    int m2 = fmenor( root->right, val );

    if ( m1 == -1 && m2 == -1) 
        return  -1;
    if ( m1 == -1 || m2 == -1 )
        return fmax ( m1 , m2 );
    else
        return fmin( m1, m2 );
}

int findSecondMinimumValue ( struct TreeNode* root ) {
    
    return fmenor( root, root->val );
}

void imprime ( TreeNode *p ) {
    if ( p != NULL )
    {
        printf( " %d ", p->val );
        imprime ( p->left );
        imprime ( p->right );
    }

    return;
}