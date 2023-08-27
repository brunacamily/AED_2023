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

no* insere(no *p, int dado){
    if (p == NULL)
    {
        no *a = (no*)malloc(sizeof(no));
        a->dado = dado;
        a->pEsq  = NULL;
        a->pDir = NULL;
        return a;
    }else {
        if(dado < p->dado)
            p->pEsq = insere(p->pEsq,dado);
        else 
            p->pDir = insere(p->pDir,dado);
        return p;        
    }
}


void imprime(no *p) {
    if (p != NULL)
    {
        printf(" %d ", p->dado
        );
        imprime(p->pEsq);
        imprime(p->pDir);
    }
    return;
}