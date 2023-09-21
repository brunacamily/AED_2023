#include <stdio.h>

void Insertionsort(int a[], int n);

int main( )
{
    int a[5]={1,2,3,4,5};
    Insertionsort(a,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    
    return 0;
}

void Insertionsort(int a[], int n)
{
    int aux, i, j;
    for (j = 1; j < n; j++)
    {
        i = j - 1;
        aux = a[j];
        while ((i >= 0) && (aux < a[i]))
        {
            a[i + 1] = a[i];
            i--;
        }

        a[i + 1] = aux;
    }

}