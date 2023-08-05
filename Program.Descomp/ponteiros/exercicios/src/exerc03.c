/*
Faca um programa que leia 2 valores inteiros e chame uma funcÂ¸ao que receba estas Ëœ
2 variaveis e troque o seu conte Â´ udo, ou seja, esta funcÂ¸ Â´ aoËœ e chamada passando duas Â´
variaveis A e B por exemplo e, ap Â´ os a execucÂ¸ Â´ ao da funcÂ¸ Ëœ ao, A conter Ëœ a o valor de B e B Â´
tera o valor de A.
*/

#include <stdio.h>

void TrovaValor(int *pa, int *pb);

int main( )
{   
    int a, b, *pA, *pB;

    pA = &a;
    pB = &b;

    printf("Digite A: ");
    scanf("%d", &a);
    printf("Digite B: ");
    scanf("%d", &b);

    printf("\nA=%d e B = %d ", a, b);

    TrovaValor( pA, pB);

    printf("\nA=%d e B = %d ", a, b);

    return 0;
}

void TrovaValor(int *pa, int *pb){
    int aux;

    aux = *pa;
    *pa = *pb;
    *pb = aux;

}