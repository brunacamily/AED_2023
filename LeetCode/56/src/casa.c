#include <stdio.h>
#include <stdlib.h>

//input: [[1,3],[2,6],[8,10],[15,18]] --- [[1,4],[4,5]]
// output :[[1,6],[8,10],[15,18]]     --- [[1,5]]


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes);
int** insere(int* novo,int* tamSaida, int** retorno);

int main()
{
    int **saida=NULL, *tamSaida, *ultimoLido = NULL, i =0 ;

    int **interv = (int**)malloc(sizeof(int*)*3); 
    int *inter1 = (int*)malloc(sizeof(int)), 
        *inter2 = (int*)malloc(sizeof(int)),
        *inter3 = (int*)malloc(sizeof(int));; 
    tamSaida = (int*)malloc(sizeof(int));
    tamSaida = &i;

    inter1[0] = 1; 
    inter1[1] = 4; 
    inter2[0] = 4; 
    inter2[1] = 5;
    inter3[0] = 6; 
    inter3[1] = 7;

    interv[0] = inter1;
    interv[1] = inter2;
    interv[2] = inter3;
    printf("teste01\n");
/*    
saida = insere(inter1, tamSaida, saida);
saida = insere(inter2, tamSaida, saida);
saida = insere(inter3, tamSaida, saida);
*/

  saida = merge(interv, 3, ultimoLido, tamSaida, saida);

    printf("teste02\n");

    printf("%d ", saida[0][0]);
    printf("%d ", saida[0][1]);
    printf("%d ", saida[1][0]);
    printf("%d ", saida[1][1]);

    return 0;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){


    if(intervals == NULL)
        return NULL;
    
    if(intervalsColSize == NULL){
        intervalsColSize = (int*)malloc(sizeof(int)*2);
        intervalsColSize[0] = intervals[0][0];
        intervalsColSize[1] = intervals[0][1];
        printf("%d ", intervalsColSize[0]);
        printf("%d ", intervalsColSize[1]);
        printf("\n\n");
    }

    for (int j=1; j<intervalsSize; j++)
    {
        if(intervals[j][0] <= intervalsColSize[1]){
            if ( intervals[j][1] > intervalsColSize[1] ){
                intervalsColSize[1] = intervals[j][1];  
                returnColumnSizes = insere(intervalsColSize, returnSize, returnColumnSizes) ;  
                
            }
        }


         if(intervals[j][0] > intervalsColSize[1]){
            printf("teste\n");
            printf("tam%d\n", *returnSize);
           returnColumnSizes = insere(intervalsColSize, returnSize, returnColumnSizes) ;
        } 
        
            
        
    }
    return returnColumnSizes;
}

int** insere(int* novo, int* tamSaida, int** retorno){
    
    int *aux = (int*)malloc(sizeof(int)*2); 
    aux[0] = novo[0];
    aux[1] = novo[1];
     
    retorno = (int**)realloc(retorno, sizeof(int*));
    retorno[*tamSaida] = (int*)malloc(sizeof(int));
    retorno[*tamSaida] = aux;

    *tamSaida = *tamSaida + 1;

    return retorno;
}