// bruna camily - exercicio 56

//input: [[1,3],[2,6],[8,10],[15,18]] --- [[1,4],[4,5]]
// output :[[1,6],[8,10],[15,18]]     --- [[1,5]]

/*
parametros :
array de arrays
quantos arrays
ultimo array lido
quantos arrays foram lidos[
array de arrays final
]
*/
#include <stdio.h>
#include <stdlib.h>


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes);
int** insere(int* novo,int* tamSaida, int** retorno);

int main()
{
    int **saida, *tamSaida, *ultimoLido = NULL, i =0 ;
    int **interv = (int**)malloc(sizeof(int*)*2); 
    int *inter1 = (int*)malloc(sizeof(int)), 
    *inter2 = (int*)malloc(sizeof(int)); 
    tamSaida = (int*)malloc(sizeof(int));
    tamSaida = i;

    inter1[0] = 1; 
    inter1[1] = 4; 
    inter2[0] = 4; 
    inter2[1] = 5;

    interv[0] = inter1;
    interv[1] = inter2;

    printf("teste01\n");

    saida = merge(interv, 2, ultimoLido, tamSaida, saida);

    printf("teste02\n");
    return 0;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){

    if(intervals == NULL)
        return NULL;
    
    if(intervalsColSize == NULL){
        intervalsColSize = (int*)malloc(sizeof(int)*2);
        intervalsColSize[0] = *intervals[0];
        intervalsColSize[0] = *intervals[0]++;

        if ( intervalsSize >= 2 )
        {
            intervalsSize--;
            intervals += 2;
        }
        
        returnColumnSizes = (intervals, intervalsSize, intervalsColSize, returnSize, returnColumnSizes);
    }

    int i=0;
    while (i<intervalsSize)
    {
        if(intervals[i] < intervalsColSize[1]){
            intervalsColSize[1] = intervals[i]++;
            if ( intervalsSize >= 2 )
                {
                    intervalsSize--;
                    intervals += 2;
                }
        }else{
           returnColumnSizes = insere(intervalsColSize, returnSize, returnColumnSizes) ;
        }
            
        i++;
    }
}

int** insere(int* novo,int* tamSaida, int** retorno){
    *tamSaida++;
    int aux[2];
    aux[0] = novo[0];
    aux[1] = novo[1];
    retorno = (int**)malloc(sizeof(int*));
    retorno[*tamSaida] = (int*)malloc(sizeof(int));
    retorno[*tamSaida] = aux;

    return retorno;
}

/*
minha ideia Ã© percorrer o vetor de vetores e comparar com o vetor lido 
anteriormente e se o primeiro elemento do vetor atual for menor q o segundo elemento do
vetor lido anteriomente pego o 1Â° elemento do 1Â° vetor e o 2Â° elemento 2Â° vetor e faco uma nova combinacao
inserindo no vetor de retorno e passo p o proximo vetor caso houver;

*/