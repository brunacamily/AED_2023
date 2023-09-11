#include <stdio.h>
#include <stdlib.h>

struct no
{
    struct no *pEsq;
    struct no *pDir;
    int dado;
};

typedef struct no no;
no* insere(no *p, int dado);
void imprime_pre_ordem(no *p);
void imprime_ordem_central(no *p);
void imprime_pos_ordem(no *p);

int main (){

    no *a=NULL;
    a = insere(a, 10);
    a = insere(a, 7);
    a = insere(a, 20);
    a = insere(a, 3);
    a = insere(a, 8);
    a = insere(a, 120);

    imprime_pre_ordem(a);
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
        else if(dado > p->dado)
            p->pDir = insere(p->pDir,dado);
        else
            printf("\n\tERRO : O registro %d ja existe!\n", dado);
        return p;        
    }
}


void imprime_pos_ordem(no *p) {
    if (p != NULL)
    {
        imprime_pos_ordem(p->pEsq);
        imprime_pos_ordem(p->pDir);
        printf(" %d ", p->dado);
    }
    return;
}

void imprime_ordem_central(no *p) {
    if (p != NULL)
    {
        imprime_ordem_central(p->pEsq);
        printf(" %d ", p->dado);
        imprime_ordem_central(p->pDir);
    }
    return;
}

void imprime_pre_ordem(no *p) {
    if (p != NULL)
    {
        printf(" %d ", p->dado);
        imprime_pre_ordem(p->pEsq);
        imprime_pre_ordem(p->pDir);
    }
    return;
}

void Zera ( no *p ) {
    if ( p->pEsq == NULL && p->pDir == NULL)
    {  
        free ( p );
    }else{
        if ( p->pEsq != NULL )
            Zera ( p->pEsq );
        if ( p->pDir != NULL )
            Zera ( p->pDir );
    }
}

void exclui_no ( no *p) {
    
}