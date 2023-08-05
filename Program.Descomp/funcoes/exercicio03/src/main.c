/* Crie uma funcao que receba como parametro um valor inteiro e gere como saÄ±da n linhas
com pontos de exclamacao, conforme o exemplo abaixo (para n = 5): */

#include <stdio.h>

void piramede(int n);
int main(){
    int num;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    piramede(num);
}

void piramede(int n){
    int i, j;
    for(i=1; i<=n; i++){
        for(j=1; j<=i; j++){
            printf("!");
        }
        printf("\n");
    }
}