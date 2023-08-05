/* Facao uma funcao que receba a data atual (dia, mes e ano em inteiro) e exiba-a na tela Ã‹â€ 
no formato textual por extenso. Exemplo: Data: 01/01/2000, Imprimir: 1 de janeiro de
2000. */

#include <stdio.h>
#include <string.h>

void data(int dia, int mes, int ano);

int main(){
   int dia, mes, ano;
  
   printf("Digite a data de hoje: ");
   printf("\n Dia:  ");
   scanf("%d", &dia);
   while(dia<=0 || dia>=32){
    printf("\nDia:  ");
    scanf("%d", &dia);
   }

   printf("Mes:  ");
   scanf("%d", &mes);
   while(mes<=0 || mes>=13){
    printf("Mes:  ");
    scanf("%d", &mes);
   }

   printf("Ano:  ");
   scanf("%d", &ano);
   while( ano>2023){
    printf("Ano:  ");
    scanf("%d", &ano);
    
   }

   data(dia, mes, ano);

}


void data(int dia, int mes, int ano){
    
    switch (mes)
    {
    case 1:
        printf(" %d de Janeiro de %d ", dia, ano);
        break;
    case 2:
         printf(" %d de Fevereiro de %d ", dia, ano);
        break;
    
    case 3:
         printf(" %d de Marco de %d ", dia, ano);
        break;
    
    case 4:
         printf(" %d de Abril de %d ", dia, ano);
        break;
    
    case 5:
         printf(" %d de Maio de %d ", dia, ano);
        break;
    
    case 6:
         printf(" %d de Junho de %d ", dia, ano);
        break;
    
    case 7:
         printf(" %d de Julho de %d ", dia, ano);
        break;
    
    case 8:
         printf(" %d de Agosto de %d ", dia, ano);
        break;
    
    case 9:
         printf(" %d de Setembro de %d ", dia, ano);
        break;
    
    case 10:
         printf(" %d de Outubro de %d ", dia, ano);
        break;
    
    case 11:
         printf(" %d de Novembro de %d ", dia, ano);
        break;
    
    case 12:
         printf(" %d de Dezembro de %d ", dia, ano);
        break;
    
    default:
        break;
    }
}