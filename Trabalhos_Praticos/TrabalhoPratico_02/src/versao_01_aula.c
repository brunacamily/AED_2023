                
//  =====================      VERSÃO FEITA EM AULA - 04/08/2023        ================================    //

#include <stdio.h>
#include <stdlib.h>


int fillCups(int* amount, int amountSize){

    int seconds = 0, teste=0;


    do{

        if(amount[0] != 0 &&  amount[1] !=0)
        {
            amount[0] = amount[0]-1;
            amount[1] = amount[1] -1;
            seconds++;

        }else if (amount[0] != 0 &&  amount[2] !=0)
        {
            amount[0]--;
            amount[2]--;
            seconds++;

        }else if (amount[1] != 0 && amount[2] != 0)
        {
            amount[1]--;
            amount[2]--;
            seconds++;
        }else if (amount[0] != 0)
        {
            amount[0]--;
            seconds++;

        }else if (amount[1] != 0)
        {
            amount[1]--;
            seconds++;

        }else if (amount[2] != 0)
        {
            amount[2]--;
           seconds++;

        }
        teste = amount[0] +amount[1]  + amount[2];
    }while( teste != 0  );
    
    return seconds;
}



int main(void)
{
    int *array, tam = 3, temp = 0;
    array = (int*) malloc (sizeof(int) * tam);
    array[0] = 5;
    array[1] = 0;
    array[2] = 0;

    temp =  fillCups( array, tam);

    printf("\n\ttempo = %d \n", temp);

    return 0;
}