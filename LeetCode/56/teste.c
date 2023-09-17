#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a2, **a = (int **)malloc(sizeof(int*));

    a2 = (int*)malloc(sizeof(int));

    printf("Hello Word!!");
    free(a2);
    free(a);

    return 0;
}