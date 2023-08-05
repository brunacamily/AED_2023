#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
    int cod;
    char nome[40];
    float preco;
} SProduto;

typedef struct STipoFila{
    SProduto info;
    struct STipoFila* pNext;
} STipoFila;

typedef struct {
    STipoFila *pFirst;
    STipoFila *pLast;
} SFila;

SFila* reset(){
  SFila *sentinela;
  sentinela = (SFila*) malloc(sizeof(SFila));
  sentinela->pFirst = NULL;
  sentinela->pLast = NULL;

  return sentinela;
}


SProduto* create_prod(int cod, char nome[40], float preco){
    SProduto *new = malloc(sizeof(SProduto));
    new->cod = cod;
    strcpy(new->nome, nome);
    new->preco = preco;
    return new;
}

void push_fila(SFila* sentinela, SProduto* produto){
    if (sentinela->pFirst == NULL && sentinela->pLast == NULL){
        STipoFila *new = malloc(sizeof(STipoFila));
        
        new->info = *produto;
        new->pNext = NULL;
        sentinela->pFirst = new;
        sentinela->pLast = new;
    }
    else{
        STipoFila *new = malloc(sizeof(STipoFila));
        new->info = *produto;
        new->pNext = NULL;
        sentinela->pLast->pNext = new;
        sentinela->pLast = new;
    }
}

void pop_fila(SFila* sentinela){
    if (sentinela->pFirst == NULL){
        printf("\nNÃ£o hÃ¡ elementos na lista\n\n");
        return;
    }
    STipoFila* freeCell = sentinela->pFirst;
    sentinela->pFirst = freeCell->pNext;
    if (sentinela->pFirst == NULL){
        sentinela->pLast = NULL;
    }
    free(freeCell);
}

void empty_fila(SFila *sentinela){
    if(sentinela->pFirst == NULL){
        printf("\n\tFila esta vazia!");
    }else{
        printf("\n\tFila nao esta vazia!");
    }
}

void clean_list(SFila* sentila){
    while(sentila->pFirst != NULL){
        pop_fila(sentila);
    }
    printf("\nLista completamente limpa\n\n");
}

void print_fila(SFila* sentinela){
    if (sentinela->pFirst == NULL){
        printf("\nNao ha o que mostrar\n\n");
    }
    STipoFila *tracker = sentinela->pFirst;
    while (tracker != NULL){
        printf("[%d, %s, %.2f]\n", tracker->info.cod, tracker->info.nome, tracker->info.preco);
        tracker = tracker->pNext;
    }
}

int main(void){
    
    SFila *sentinela;
    
    sentinela = reset();

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

    empty_fila(sentinela);
    //pop_fila(sentinela);
    //print_fila(sentinela);

    printf("\n------------------");

    clean_list(sentinela);
    print_fila(sentinela);

    free(prod1);
    free(prod2);
    free(prod3);
    free(prod4);
    free(sentinela);

    return 0;
}