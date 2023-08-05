#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* aloca(int tam);

int main( )
{
    char *i;
    int tamanho;

    printf("Digite o tamanho da string: \n");
    scanf("%d", &tamanho);

    i = aloca(tamanho);
    int t;
    for(t=0; t<tamanho; t++){
        if(i[t]!='a' && i[t]!='e'&& i[t]!='i' && i[t]!='o' && i[t]!='u'  )
            printf("%c", i[t]);
    }

    free(i);

    return 0;
}

char* aloca(int tam){
    char *j;
    j = (char*) malloc (tam * sizeof(char));
    if( j == NULL ) {
        printf( " ERRO : SEM MEMORIA! \n" );
        exit(1); //para o cÃ³digo;
    }
    printf("\ndigite:");
    scanf("%s", j);
    return j;
}