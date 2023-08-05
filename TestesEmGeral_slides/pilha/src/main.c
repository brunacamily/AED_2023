#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Aluno Aluno;

 struct Aluno
{ 
    int matricula;
    char nome[50];
    Aluno *pnext;
};

typedef struct 
{ 
    Aluno *alunos;
    Aluno *topo; 
    Aluno *base;
    int alocados;
    int limite;
}Pilha; 

Pilha* reset(){
    Pilha *pilha;
    pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->alunos = NULL;
    pilha->base = NULL;
    pilha->topo = NULL;
    pilha->alocados = 0;
    pilha->limite = 3;
    
    return pilha;
}

Pilha* push( Pilha *pilha, Aluno *a ){
    Aluno *nova;
    nova = (Aluno*)malloc(sizeof(Aluno));
    strcpy(nova->nome, a->nome);
    nova->matricula = a->matricula;
    

    if( pilha->base == NULL){
        nova->pnext = NULL;
        pilha->base = nova;
        pilha->topo = nova;
        pilha->alocados += 1;

    } else if ( pilha->alocados < pilha->limite && pilha->base != NULL )
    {
        nova->pnext = pilha->topo;
        pilha->topo = nova;
        pilha->alocados += 1;
    } else{
        printf("\n LISTA ESTA CHEIA!\n\n");
    }

    return pilha;
}

void pop(Pilha *pilha){

    if (pilha->base == NULL){
        printf("NÃ£o hÃ¡ elementos na lista\n\n");
    }else{
        Aluno* freeCell = pilha->topo;
        pilha->topo = freeCell->pnext;
        if ( pilha->topo == NULL){
            pilha->base = NULL;
        }
        printf("\n\tAluno: %s, deletado!", freeCell->nome);
        free(freeCell);
    }

}

void pop_nome(Pilha *pilha, char *nome){
    Aluno *percorre, *apaga;
    if(pilha->base != NULL){
        percorre = pilha->topo;
        while (percorre->pnext != NULL){
            if((strcmp(percorre->pnext->nome, nome) == 0)){
                apaga = percorre->pnext;
                percorre->pnext = percorre->pnext->pnext;
                free(apaga);
                //printf("\n\tAluno(a) %s excluido", percorre->pnext->nome);
                break;
            }
            percorre = percorre->pnext;
        }
    }
}

void empty( Pilha *pilha){
    if(pilha->alocados>0){
        printf("\n\tPilha nao esta vazia!");
    }else{
        printf("\n\tPilha  esta vazia!");
    }
}

void clear(Pilha *pilha){
    if(pilha->base != NULL){
         while (pilha->base != NULL){
            pop(pilha);
         }
        printf("\n\tPilha esvaziada!");
    }

}

void print_pilha(Pilha *pilha){
    if (pilha->base == NULL){
        printf("\n\tPilha vazia, nao ha o que mostrar.");
    }
    Aluno *tracker = pilha->topo;
    while (tracker != NULL){
        printf("\n[%s, %d]\n", tracker->nome, tracker->matricula);
        tracker = tracker->pnext;
    }
}


int main(void){

    Pilha *princpal;
    Aluno *a1,*a2, *a3;
    a1 = (Aluno*)malloc(sizeof(Aluno));
    a2 = (Aluno*)malloc(sizeof(Aluno));
    a3 = (Aluno*)malloc(sizeof(Aluno));
    princpal = (Pilha*)malloc(sizeof(Pilha));

    a1->matricula = 2210;
    strcpy(a1->nome, "bruna");

    a2->matricula = 4453;
    strcpy(a2->nome, "Camily");

    a3->matricula = 7766;
    strcpy(a3->nome, "novack");

    princpal = reset();

    push(princpal, a1);
    push(princpal, a2);
    push(princpal, a3);
    print_pilha(princpal);
 //   pop(princpal);

    pop_nome(princpal, a1->nome);
printf("------------");
    print_pilha(princpal);

//    clear(princpal);
//    print_pilha(princpal);

    free(a1);
    free(a2);
    free(a3);
}