#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Faca um programa que contenha um menu com as seguintes opcoes: 
v (a) Ler uma string S1 (tamanho maximo 20 caracteres);
v (b) Imprimir o tamanho da string S1;
v (c) Comparar a string S1 com uma nova string S2 fornecida pelo usuario e imprimir o
resultado da comparacao; 
v (d) Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da
concatenacao; 
v (e) Imprimir a string S1 de forma reversa; */

int menu();
void ler_imprime(char leer[20]);
int tam_string(char n[20]);
void comparar(char lido[20], char s2[20]);
void concatena(char s1[20], char s2[20]);
void s1_reversa(char s1[20]);

int main(){
    int opicao, tam;
    char lido[20], lido02[20];
    for(;;){
        opicao = menu();
        
        switch (opicao)
    {
    case 1:
        ler_imprime(lido);
        break;
    
    case 2:
        tam = tam_string(lido);
        printf(" O tamanho da string: %d", tam);
        break;

    case 3:
        comparar(lido, lido02);
        break;
    
    case 4:
        concatena(lido, lido02);
        break;

    case 5:
        s1_reversa(lido); 
        break;
    case 6:
        exit(0);
        break;
    
    default:
        break;
    }
    }

}

int menu(){
    int c;
    do{
    printf("\n\t1. Ler uma string: \n");
    printf("\t2. Retornar tamanho da string indicada: \n");
    printf("\t3. Comparar duas strings \n");
    printf("\t4. contatenar strings: \n");
    printf("\t5. reverso de s1: \n");
    printf("-- Digite sua escolha: ");
    scanf("%d", &c);
    }while (c < 0 || c > 7);
    getchar();
    return c;
    
}

void ler_imprime(char leer[20]){
    printf("\n Digite seu nome: ");
    scanf("%[^\n]c", leer);
    getchar();
}

int tam_string(char n[20]){
    int tam;
    tam = strlen(n);
    return tam;
}

void comparar(char lido[20], char s2[20]){
    int r;
    printf("\n Digite seu nome: ");
    scanf("%[^\n]c", s2);
    getchar();
    r = strcmp(lido, s2);
    if(r == 0){
        printf(" As strings indicadas sao iguais! \n");
    }else{
        if(r > 0){
            printf("\nAlfabeticamente a primeira string inserida vem apos a segunda! ");
        }else{
            printf("\nAlfabeticamente a segunda string inserida vem apos a primeira!");
        }
    }
}

void concatena(char s1[20], char s2[20]){
    printf("\n \t %s \n",(strcat(s1,s2)));
}

void s1_reversa(char s1[20]) {
    int n, i;
    n = tam_string(s1);
    for(i = n; 0<=i; i--){
        printf(" %c", s1[i]);
    }
}