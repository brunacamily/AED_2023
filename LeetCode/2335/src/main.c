#include <stdio.h>
#include <stdlib.h>

int FillCups ( int* amount, int amountSize );
/*
====================
FillCups
 Recebe um array do tipo inteiro e o tamanho deste (3),
e retorna um  inteiro que representa o minimo em segundos 
para encher os copos.
====================
*/

void Pop ( int *copos, int *amount );
/*
====================
Pop
 Recebe dois arrays de mesmo tamanho (3),
o primeiro array guarda o indice da posiÃ§Ã£o
no segundo array que serÃ¡ decrementada.
====================
*/

void Sort ( int *amount, int *copos );
/*
====================
Sort
 A funÃ§Ã£o Pop chama a funÃ§Ã£o Sort para
que Sort coloque o indice da posiÃ§Ã£o do array 
(que serÃ¡ decremetado) com o menor conteudo
no fim do array copos, e os indices dos dois 
maiores conteudos do array amount 
no inicio do array copos.
==================== 
*/


int main ( void ) {

    int *array, tam = 3, temp = 0;
    array = ( int* ) malloc ( sizeof ( int ) * tam );
    array [ 0 ] = 4;
    array [ 1 ] = 4;
    array [ 2 ] = 0;
   
    temp =  FillCups ( array, tam );

    printf("\n\ttempo = %d \n", temp);

    free ( array );

    return 0;
}


int FillCups ( int* amount, int amountSize ) {

    if ( amountSize != 3 )
    return -1;

    int seconds = 0, teste = ( amount[ 0 ] + amount[ 1 ] + amount[ 2 ] ),
     *copos = ( int* ) calloc ( 3, sizeof ( int ) );

    while ( teste != 0 ) {
        seconds++ ;
        Pop ( copos, amount );
        teste = amount[ 0 ] + amount[ 1 ] + amount[ 2 ];
    }

    free ( copos );
    
    return seconds;
}


void Pop( int *copos, int *amount ) {

    Sort ( amount, copos );

    if ( amount [ copos [ 0 ] ] > 0 && amount [ copos [ 1 ] ] > 0 ) {
        amount [ copos [ 0 ] ] -- ; 
        amount [ copos [ 1 ] ] -- ;
    } else if ( amount [ copos [ 0 ] ] > 0 ) {
        amount[copos[0]]--;
    } else if ( amount [ copos [ 1 ] ] > 0 ) {
        amount [ copos [ 1 ] ] -- ;
    }

}


void Sort ( int *amount, int *copos ) { 

    copos[0] = amount[0]; copos[1] = 0;

    for ( int j = 0; j < 3; j++ ) {
       if ( copos [ 0 ] > amount [ j ] ) {
            copos [ 0 ] = amount [ j ];
            copos [ 1 ] = j; 
       }
    }

    copos [ 2 ] = copos [ 1 ];

    if ( copos [ 2 ] == 0 ) {
        copos [ 0 ] = 1;
        copos [ 1 ] = 2;
    } else
    if ( copos [ 2 ] == 1 ) {
        copos [ 0 ] = 0;
        copos [ 1 ] = 2;
    } else
    if ( copos [ 2 ] == 2 ) {
        copos [ 0 ] = 0;
        copos [ 1 ] = 1;
    }

}