#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 struct TreeNode {
      int val;
      struct TreeNode *left;   // esquerda 
      struct TreeNode *right;   // direita 
  };

typedef struct TreeNode TreeNode;

int FindSecondMinimumValue ( struct TreeNode* root );

/*
====================
findSecondMinimumValue
 Têm como parâmetro um ponteiro do tipo TreeNode e retorna o valor do segundo menor nó. 
 Esta função apenas chama a função fmenor().
====================
*/

int Fmenor_r ( struct TreeNode* root, int val );

/*
====================
fmenor
 Têm como parâmetro um ponteiro do tipo TreeNode e um inteiro que sempre é a raiz de uma subarvore 
diferente de sua raiz, esta função é recursiva de sempre testa quem é o segundo menor valor de um nó 
e seus dois filhos e o retorna, caso exista.
====================
*/

void CriaArvoreTeste ( TreeNode *ini );

/*
====================
criaArvoreTeste
 cria a arvore teste de uma só vez apartir do ponteiro TreeNode passado.
====================
*/

void Imprime ( TreeNode *p );

/*
====================
Imprime
 imprime a árvore passada em pre-ordem.
====================
*/

void Zera ( TreeNode *p );

/*
====================
Zera
 Dá free em todos os nós da árvore, exceto na raiz;
====================
*/

int main( )
{ 
    TreeNode *p = ( TreeNode * ) malloc ( sizeof( TreeNode ) ) ;
    CriaArvoreTeste(p);

    Imprime( p );

    int teste;
    teste = FindSecondMinimumValue( p );

    printf( " \nTESTE:%d ", teste );

    Zera ( p );
    free ( p );
    return 0;
}

void CriaArvoreTeste (  TreeNode *ini  ){

    TreeNode *p1 = ( TreeNode * ) malloc ( sizeof( TreeNode ) ) ;
    p1->val = 2;
    p1->left = NULL;
    p1->right = NULL;

    TreeNode *p3 = ( TreeNode * ) malloc ( sizeof( TreeNode ) ) ;
    p3->val = 5;
    p3->left = NULL;
    p3->right = NULL;

    TreeNode *p4 = ( TreeNode * ) malloc ( sizeof( TreeNode ) ) ;
    p4->val = 7;
    p4->left = NULL;
    p4->right = NULL;

    TreeNode *p2 = ( TreeNode * ) malloc ( sizeof( TreeNode ) ) ;
    p2->val = 5;
    p2->left = p3;
    p2->right = p4;
    
    ini->val = 2;
    ini->left = p1; 
    ini->right = p2;

}

void Imprime ( TreeNode *p ) {
    if ( p != NULL )
    {   printf( " %d ", p->val );
        Imprime ( p->left );
        Imprime ( p->right );
    }

    return;
}

void Zera ( TreeNode *p ) {
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

int FindSecondMinimumValue ( struct TreeNode* root ) {
      
    return Fmenor_r ( root, root->val );
}

int Fmenor_r ( struct TreeNode* root, int val ) {
    if ( root == NULL )
        return -1;
    if ( root->val != val )
        return root->val;
        
    int m1 = Fmenor_r ( root->left, val );
    int m2 = Fmenor_r ( root->right, val );

    if ( m1 == -1 && m2 == -1) 
        return  -1;
    if ( m1 == -1 || m2 == -1 )
        return fmax ( m1 , m2 );
    else
        return fmin( m1, m2 );
}