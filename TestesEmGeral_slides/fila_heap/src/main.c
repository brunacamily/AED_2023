//problema na ordenacao 

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

void push_fila(SFila* sentinela, SProduto *produto){
    STipoFila *new = malloc(sizeof(STipoFila));
    new->info.cod = produto->cod;
    strcpy(new->info.nome, produto->nome);
    new->info.preco = produto->preco;
    new->pNext = NULL;

    if (sentinela->pFirst == NULL && sentinela->pLast == NULL){
        new->pNext = NULL;
        sentinela->pFirst = new;
        sentinela->pLast = new;

    }else if (sentinela->pLast->info.cod > produto->cod){

        if(sentinela->pFirst->info.cod < produto->cod){
            STipoFila *temp = sentinela->pFirst;
            sentinela->pFirst = new; 
            sentinela->pFirst->pNext = temp;
            
        } else {
//--------------------------------------------------------------------
        STipoFila *fila = sentinela->pFirst;
        while(fila->pNext != NULL){

            if(fila->info.cod > produto->cod){
                STipoFila *temp = fila->pNext;
                fila->pNext = new;
                new->pNext = temp; 

            }else if(fila->info.cod <= produto->cod) {
                continue;
            }
        }
//---------------------------------------------------------------------
        }


    }else if (sentinela->pLast->info.cod <= produto->cod)
            {
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
        printf("Nao ha o que mostrar\n\n");
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
    SProduto *prod1 = create_prod(3, nome, 10.00);

    strcpy(nome, "segundo");
    SProduto *prod2 = create_prod(10, nome, 10.00);

    strcpy(nome, "terceiro");
    SProduto *prod3 = create_prod(9, nome, 10.00);
    
    

    push_fila(sentinela, prod1);

    push_fila(sentinela, prod2);

    push_fila(sentinela, prod3);


    print_fila(sentinela);


    free(prod1);
    free(prod2);
    free(prod3);
   

    free(sentinela);


    return 0;
}