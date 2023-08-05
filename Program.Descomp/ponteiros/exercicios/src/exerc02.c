/*
 Escreva um programa que contenha duas variaveis inteiras. Compare seus enderecos e exiba o maior endereco.
*/
#include <stdio.h>

int main( )
{
    int  var01 = 98, var02 = 100 , *pVar01, *pVar02;
    pVar01 = &var01;
    pVar02 = &var02;    

    if( &var01 > &var02 ){
        printf(" o maior end: %n \n contendo:%d", pVar01, var01);
    } else if( &var01 < &var02 ){
        printf(" o maior end: %n \n contendo:%d", pVar02, var02);
    }

    return 0;
}


// o maior end. maior Ã© o  da variavel que foi declarada primeiro.