#include <stdio.h>
#include <stdlib.h>

void zera1 ( int **a, int tam );
/*
====================
zera1
 Dá free nos ponteiros de ponteiros (matrizes).
====================
*/

void Quicksort ( int **data, int inicio, int fim );
/*
====================
Quicksort
 Reordena os intervalos passados em forma de matriz passados 
como parâmetro levando em consideração o elemento zero de cada linha.
====================
*/

int** Merge ( int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes );
/*
====================
Merge
 Testa os intervalos passados no ponteiro intervals (matriz), 
e caso haja sobreposição de intervalos ajusta o intervalos para que 
não hajam sobreposições e retorna a matriz ajustada.
====================
*/

int main( ) {
    
    int **saida  = ( int ** ) malloc ( sizeof ( int * ) ), 
        *ultimoLido = NULL, i = 0,
        **interv = ( int ** ) malloc ( sizeof ( int * ) * 2 ),
        **col = ( int ** ) malloc ( sizeof ( int * ) ),
        *inter1 = ( int * ) malloc ( sizeof ( int ) * 2 ), 
        *inter2 = ( int * ) malloc ( sizeof ( int ) * 2 ), 
        *tamSaida = ( int * ) malloc ( sizeof ( int ) );

    tamSaida = &i;

    inter1 [ 0 ] = 1; 
    inter1 [ 1 ] = 4; 
    inter2 [ 0 ] = 4; 
    inter2 [ 1 ] = 6;

    interv [ 0 ] = inter2;
    interv [ 1 ] = inter1;

   saida = Merge ( interv, 2, ultimoLido, tamSaida, col );

   printf("%d ", saida[0][0]);
   printf("%d ", saida[0][1]);

    free ( tamSaida );
    free ( inter1 );
    free ( inter2 );
    free ( interv );
    zera1 ( col, 1 );
    zera1 ( saida,1 );

    return 0;
}


void zera1 ( int **a, int m) {
    for ( int i = 0; i < m; i++ ) {
        free ( a [ i ] );
    } 
    free ( a );
}


void Quicksort ( int **data, int inicio, int fim ) {
    int esq, dir, pivo, *aux;
    esq = inicio;
    dir = fim ;
    pivo = data [ ( inicio + fim ) / 2 ] [ 0 ] ;
    do {
        while ( data [ esq ] [ 0 ] < pivo )
            esq ++;
        while ( data [ dir ] [ 0 ] > pivo )
            dir--;

        if ( esq <= dir ) {
            aux = data [ esq ];
            data [ esq ] = data [ dir ];
            data [ dir ] = aux;
            esq ++;
            dir --;
        }
    } while ( esq <= dir );

    if ( inicio < dir )
        Quicksort ( data, inicio, dir );
    if ( esq < fim )
        Quicksort ( data, esq, fim );
}


int** Merge ( int** intervals, int intervalsSize, int * intervalsColSize, int* returnSize, int** returnColumnSizes ) {
    Quicksort ( intervals, 0, intervalsSize - 1 );
    * returnColumnSizes  = ( int* ) malloc ( sizeof ( int ) * 10000 );
    int **teste = ( int** ) malloc ( sizeof ( int* ) * 10000 );
    teste [ 0 ] = ( int* ) malloc (sizeof ( int ) * 2 );
    teste [ 0 ] [ 0 ] = intervals [ 0 ] [ 0 ];
    teste [ 0 ] [ 1 ] = intervals [ 0 ] [ 1 ];
    ( * returnColumnSizes ) [ 0 ] = 2;
    int count = 1;
    int i = 1;
    while ( i < intervalsSize ) {
        if ( teste [ count - 1 ] [ 1 ] < intervals [ i ] [ 0 ] ) {
            
            teste[ count ] = ( int * ) malloc ( sizeof ( int ) * 2 );
            teste [ count ] [ 0 ] = intervals [ i ] [ 0 ];
            teste [ count ] [ 1 ] = intervals [ i ] [ 1 ];
            ( * returnColumnSizes ) [ count ] = 2;
            count ++;
        } else if ( teste [ count - 1 ] [ 1 ] >= intervals [ i ] [ 0 ] ) {
            if ( teste [ count - 1 ] [ 1 ] < intervals [ i ] [ 1 ] ) {
                teste [ count - 1 ] [ 1 ] = intervals [ i ] [ 1 ];
            } 
        }
        i++;
    }
    
    * returnSize = count;
    return teste;
    
}
