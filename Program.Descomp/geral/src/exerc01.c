#include <stdio.h>
#include <stdlib.h>

int main ( ) {
    int *p;

    p = ( int * ) malloc ( 5 * sizeof( int ) );
    if( p == NULL ) {
        printf( " ERRO : SEM MEMORIA! \n" );
        exit(1); //para o codigo;
    }
    
    int i;
    for( i = 0; i < 5; i++ ) {
        printf ( "Digite o conteudo do vetor[%d]: ", i );
        scanf ( "%d", &p[i] );
    }
    
    for( i = 0; i < 5; i++ ) {
        printf ( "\n vetor[%d] = %d ", i, p[i] );
    }

    
    free(p);

}