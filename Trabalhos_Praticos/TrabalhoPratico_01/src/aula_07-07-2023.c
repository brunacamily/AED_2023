/*  CODIGO FEITO EM AULA   */

#include <stdio.h>
#include <string.h>

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize);

int main(){
    char *licensePlate={"1s3 PSt"}, **words={"step""steps""stripe""stepple"}, tamanho=4, saida[20];
    strcpy(saida,(hortestCompletingWord( licensePlate, words, tamanho)));

}

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
    int j, i=0, t[15], p=0, tword=0;
    char aux[100], palavras[10][15], *saida[20];

    for(i=0; i<100; i++){
        if(*licensePlate!='\0'){
            strcpy(aux[i], *licensePlate);
            licensePlate+=1;
        }
    }
    for(j=0; j<wordsSize; j++){
        for(i=0; i<100; i++){
            do{
                strcpy(palavras[j][i], **words);
                licensePlate+=1;
            }while(**words != '\0');
        }

    }
    for(j=0; j<wordsSize; j++){
        for(i=0; i<100; i++){
            while(aux){
                t[j] = strcmp(aux[p], palavras[j][i]);
                p++;
            }
        }
    }
    for(i=0; i<100; i++){
        if(t[i]== strlen(palavras[i])){
            strcpy(saida, palavras[i] );
        }
    }

    return saida;
}