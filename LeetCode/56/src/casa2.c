#include <stdio.h>
#include <stdlib.h>

//input: [[1,3],[2,6],[8,10],[15,18]] --- [[1,4],[4,5]]
// output :[[1,6],[8,10],[15,18]]     --- [[1,5]]


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes);
int** insere(int* novo,int tamSaida, int** retorno);

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
    printf("%d ", saida[2][0]);
    printf("%d %d ", saida[2][1], *tamSaida);
    return 0;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    
    returnColumnSizes = (int**)malloc(sizeof(int*) * 10000);
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * 2 );
    returnColumnSizes[0][0] = intervals[0][0];
    returnColumnSizes[0][1] = intervals[0][1];

    int count = 1;
    for (int i=1; i<intervalsSize; i++) {
        if (returnColumnSizes[count-1][1] < intervals[i][0]) {
            
            returnColumnSizes[count] = (int *)malloc(sizeof(int) * 2 );

            returnColumnSizes[count][0] = intervals[i][0];
            returnColumnSizes[count][1] = intervals[i][1];
            
            count++;
        } else if (returnColumnSizes[count-1][1] >= intervals[i][0]) {
            if (returnColumnSizes[count-1][1] < intervals[i][1]) {
                returnColumnSizes[count-1][1] = intervals[i][1];
            } 
        }
    }
    
    *returnSize = count;
    return returnColumnSizes;
    
}