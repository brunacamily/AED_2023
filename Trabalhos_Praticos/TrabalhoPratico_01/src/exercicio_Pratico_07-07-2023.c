#include <stdio.h>                               // exerciÂ­cio LeetCode: 748
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* ShortestCompletingWord ( char* licensePlate, char** words, int wordsSize );

/*
====================
shortestCompletingWord

 Esta funÃƒÂ§ÃƒÂ£o recebe 3 argumentos, o primeiro ÃƒÂ© uma string que contÃƒÂ©m letras, nÃƒÂºmeros e outros caracteres, 
 o segundo argumento ÃƒÂ© uma matriz de caracteres que contÃƒÂ©m palavras com caracteres alfabÃƒÂ©ticos e o terceiro
 argumento ÃƒÂ© o comprimento da matriz informada no segundo argumento.
 Esta funÃƒÂ§ÃƒÂ£o retorna a ultima palavra que contÃƒÂ©m os caracteres da primeira string.
====================
*/


int main ( ) {

    char licensePlate [8] =  "1s3 456"  ;
    char* words[] = { "looks","pest","stew","show"  };
    int tam = 4;
    char* resultado = ShortestCompletingWord ( licensePlate, words, tam );
    printf("\nSaida: %s", resultado);

    return 0;
}

char* ShortestCompletingWord ( char* licensePlate, char** words, int wordsSize ) {

    int i, j, tam, *tWords = malloc ( wordsSize * sizeof ( int ) );
    char* auxiliar = malloc ( strlen ( licensePlate ) + 1 );
    char** palavra = malloc ( wordsSize * sizeof ( char* ) );
    char** saidas = malloc ( wordsSize * sizeof ( char* ) );

    tam = strlen(licensePlate);
    int c = 0;

    for ( i = 0; i < tam; i++ ) {
        if ( isdigit ( licensePlate [ i ] )  == 0 && licensePlate [ i ]  != ' ' ) {
            auxiliar [ c ] = tolower ( licensePlate [ i ] );
            c++;
        }
    }


    auxiliar [c] = '\0';
    strcpy( licensePlate, auxiliar );
    tam = strlen ( auxiliar );


    for ( i = 0; i < wordsSize; i++ ) {
        palavra[i] = malloc ( strlen ( words[i] ) + 1 );
        strcpy ( palavra[ i ], words [ i ] );
        tWords [i] = 0;
    }


    for ( i = 0; i < wordsSize; i++ ) {
        int t = strlen ( palavra [ i ] );
        for ( j = 0; j < t; j++ ) {
            int j1 = tam;
            for ( int i1 = 0; i1 < j1; i1++) {
                if ( palavra [ i ] [ j ] == auxiliar [ i1 ] ) {
                    tWords [ i ] ++;
                    auxiliar [ i1 ] = '-';
                    j++;
                }
            }
        }
        strcpy ( auxiliar, licensePlate );
    }


    int cont = 0;


    for ( i = 0; i < wordsSize; i++ ) {
        if ( tWords[ i ] == tam ) {
            saidas [ cont ] = malloc ( strlen ( palavra [ i ] ) + 1 );
            strcpy ( saidas [ cont ], palavra [ i ] );
            cont++;
        }
    }


    int pMenor = -1, t = 0;


    for ( i = 0; i < cont; i++ ) {
        if ( pMenor < 0 ) {
            pMenor = i;
        } else {
            if ( ( c = strlen ( saidas [ i ] ) ) <  (t = strlen ( saidas [ pMenor ] ) ) ) {
                pMenor = i;
            }
        }
    }

    strcpy ( licensePlate, saidas [ pMenor ] );

    for ( i = 0; i < wordsSize; i++ )
       free ( palavra [ i ] );

    for ( i = 0; i < cont; i++ ) 
       free ( saidas [ i ] );

    free ( auxiliar );
    free ( tWords );


    printf ( "\nTeste saida:%s", licensePlate ) ;    // teste saiÂ­da

    return licensePlate;
}