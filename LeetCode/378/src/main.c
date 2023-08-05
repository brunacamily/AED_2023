//exercicio 387 

#include <stdio.h>
#include <string.h>

int firstUniqChar(char * s);

int main()
{
    int r=0;
    char s[20]="aabb";
    r = firstUniqChar(s);

    printf("r=%d \n c: %c", r, s[r]);
    return 0;
}

int firstUniqChar(char * s){
    char Nrepete;
    int j=0, tam=0, menor=0, aux[2][26]={0};
    tam = strlen(s);
    menor = s[j] - 'a';

     for(j=0; j<tam; j++){
            if(aux[0][s[j] - 'a'] >= 1){
                aux[0][s[j] - 'a']+=1;
            }else{
                aux[0][s[j] - 'a']+=1;
                aux[1][s[j] - 'a'] = j;
            }
     }
    
    for(j=tam-1; j>=0; j--){
       if(aux[0][s[j] - 'a'] == 1  ){
        
        if( Nrepete=='\0'){
            menor = aux[1][s[j] - 'a'];
            Nrepete = s[menor];
        }else if(aux[1][s[j] - 'a']<=menor){
            menor = aux[1][s[j] - 'a'];
            Nrepete = s[menor];
        }
           
       }
    }
    if(Nrepete!='\0'){
        return menor;
    }else{
        return -1;
    }
}