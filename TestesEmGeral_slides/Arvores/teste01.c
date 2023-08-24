#include <stdio.h>
#include <stdlib.h>

struct no
{
    struct no *pEsq;
    struct no *pDir;
    int dado;
};

typedef struct no no;

int main (){

}

no* cria( ) {
    no *novo = (no*)malloc(sizeof(no));
    novo->dado = 0;
    novo->pDir = NULL;
    novo->pEsq = NULL;
    return novo;
    
}

void insere (no *p, int info){
    no *aux = p;
    if(aux->dado < info){
        if(aux->pEsq == NULL){

        }
        aux = aux->pEsq;
        
    }else
    {
        
    }
    
}
