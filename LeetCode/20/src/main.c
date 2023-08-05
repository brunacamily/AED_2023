#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char * s);
int casos(char *s, int indiceTeste, int tamS);

int main(){
    char palavra[40]="((";
    bool a;
    a = isValid(palavra);
    if(a == true){
        printf(" VERDADEIRO!");
    }else if(a == false) {
        printf(" FALSO!");
    }
return 0;
}

bool isValid(char * s){
    int tam = strlen(s), i=0, j=0;
    char aux[tam];
    if(tam%2 != 0)
    return false;
     printf("tam:%d.\n",tam);
    for(i=0; i<tam; i++){

        if( ( s[i]=='(' ) || ( s[i]=='{' ) || ( s[i]=='[' ) ){
            aux[j] = s[i];
            j++;
            aux[j]='\0';

            printf("aux=%s.\n",aux);

        } else if (  ( s[i]==')' ) || ( s[i]=='}' ) || ( s[i]==']' )  ){
            if( s[i]==')' ){
                if ( aux[j-1]=='(' )
                {
                    aux[j-1] = '\0';
                    printf(".%s.", aux);
                    j--;
                } else {
                        return false;
                }
            } else if ( s[i]=='}' )
            {
                if ( aux[j-1]=='{' )
                {
                    aux[j-1] = '\0';
                    j--;
                } else {
                        return false;
                }
            }else if ( s[i]==']' )
            {
                if ( aux[j-1]=='[' )
                {
                    aux[j-1] = '\0';
                    j--;
                } else {
                        return false;
                }
            }
            
            
        }
        
    }
    printf("fim=%s.\n",aux);
    if(aux[0] == '\0')
    return true;
    return false;
}