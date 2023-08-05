#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
    int cod;
    char nome[40];
    float preco;
} SProduto;

typedef struct STipoFila{//Tive que nomear
    SProduto info;
    struct STipoFila* pNext;
} STipoFila;

typedef struct {
    STipoFila *pFirst;
    STipoFila *pLast;
} SFila;

SProduto* create_prod(int cod, char nome[40], float preco){
    SProduto *new = malloc(sizeof(SProduto));
    new->cod = cod;
    strcpy(new->nome, nome);
    new->preco = preco;
    return new;
}

void push_fila(SFila* sentinela, SProduto* produto){
    if (sentinela->pFirst == NULL && sentinela->pLast == NULL){
        STipoFila *new = malloc(sizeof(STipoFila));//Aqui tava com malloc(sizeof(SFila)), ou seja, tava alocando um sentinela
                                                    //e tentando acessar uma informaÃ§Ã£o de uma struct STipoFila. Erro de autocomplete.
        new->info = *produto;
        new->pNext = NULL;
        sentinela->pFirst = new;
        sentinela->pLast = new;
    }
    else{
        STipoFila *new = malloc(sizeof(STipoFila));//O mesmo aqui...
        new->info = *produto;
        new->pNext = NULL;
        sentinela->pLast->pNext = new;
        sentinela->pLast = new;
    }
}

void pop_fila(SFila* sentinela){
    if (sentinela->pFirst == NULL){
        printf("NÃ£o hÃ¡ elementos na lista\n\n");
        return;
    }
    STipoFila* freeCell = sentinela->pFirst;
    sentinela->pFirst = freeCell->pNext;
    if (sentinela->pFirst == NULL){
        sentinela->pLast = NULL;
    }
    free(freeCell);
}

void clean_list(SFila* sentila){
    while(sentila->pFirst != NULL){
        pop_fila(sentila);
    }
    printf("Lista completamente limpa\n\n");
}

void print_fila(SFila* sentinela){
    if (sentinela->pFirst == NULL){
        printf("NÃ£o hÃ¡ o que mostrar\n\n");
    }
    STipoFila *tracker = sentinela->pFirst;
    while (tracker != NULL){
        printf("[%d, %s, %.2f]\n\n", tracker->info.cod, tracker->info.nome, tracker->info.preco);
        tracker = tracker->pNext;       //E esqueci de avanÃ§ar o ponteiro tracker, sem avanÃ§o, loop infinito; (Coisa que o for do Marilton obrigaria a resolver)
    }
}

int main(void){
    
    SFila *sentinela;
    sentinela = (SFila*) malloc(sizeof(SFila));
    sentinela->pFirst = NULL;
    sentinela->pLast = NULL;
    char nome[40] = "primeiro";
    SProduto *prod1 = create_prod(00, nome, 10.00);
    strcpy(nome, "segundo");
    SProduto *prod2 = create_prod(01, nome, 10.00);
    strcpy(nome, "terceiro");
    SProduto *prod3 = create_prod(02, nome, 10.00);
    strcpy(nome, "quarto");
    SProduto *prod4 = create_prod(03, nome, 10.00);
    push_fila(sentinela, prod1);
    push_fila(sentinela, prod2);
    push_fila(sentinela, prod3);
    push_fila(sentinela, prod4);

    print_fila(sentinela);

    //pop_fila(sentinela);
    //print_fila(sentinela);

    //clean_list(sentinela);
    //print_fila(sentinela);

    free(prod1);
    free(prod2);
    free(prod3);
    free(prod4);
    free(sentinela);

    

    //primeiro caso: primeiro;
    //Segundo caso: segundo;
    //Terceiro caso: a partir de 3;

    return 0;
}