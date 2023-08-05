#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int vetor[5], vetor2[5];


    int i;
    for(i=0; i<5; i++){
        printf("Digite: ");
        scanf("%d", &vetor[i]);
    }
    int j=0;
    for(i=5; i>0; i--){
       // printf("\n %d", vetor[i]);
        vetor2[j] = vetor[i];
        j++;
    }
    for(i=0; i<5; i++){
        printf("\n %d", vetor2[i]);
    }
}