#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int tam, *p, par=0, impar=0;
    printf("Qual o tamanho escolhido para o vetor? \n");
    scanf("%d", &tam);

    p = (int*)malloc(tam * sizeof(int));
    if( p == NULL ) {
        printf( " ERRO : SEM MEMORIA! \n" );
        exit(1); //para o codigo;
    }

    int i;
    for( i = 0; i < tam; i++ ) {
        printf("\nDigite p[%d]: ", i);
        scanf("%d", &p[i]);
    }

    for( i = 0; i < tam; i++ ){
        if( p[i]%2 == 0){
            par++;
        }else if(p[i]%2 != 0){
            impar++;
        }
    }

    printf("\n  PARES: %d \n IMPARES: %d ", par, impar);

    free(p);

    return 0;
}