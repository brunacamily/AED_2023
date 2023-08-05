#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int tam, *p;
    printf("Qual o tamanho escolhido para o vetor? \n");
    scanf("%d", &tam);

    p = (int*)malloc(tam * sizeof(int));
    if( p == NULL ) {
        printf( " ERRO : SEM MEMORIA! \n" );
        exit(1); //para o cÃ³digo;
    }

    int i;
    for( i = 0; i < tam; i++ ) {
        printf("\nDigite p[%d]: ", i);
        scanf("%d", &p[i]);
    }

    for( i = 0; i < tam; i++ )
        printf("\n  p[%d] = %d ", i, p[i]);

    free(p);

    return 0;
}