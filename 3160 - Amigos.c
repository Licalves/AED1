//lista ponteiro strings

#define MAX 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lista {
    char nome[MAX];
    struct lista *seguinte;
};



int main(void){

    struct lista nova;
    struct lista luiggy;

    char listaL[MAX], listaN[MAX];

    fgets(listaL, sizeof(listaL), stdin);
    listaL[strlen(listaL)-1] = '\0';

    fgets(listaN, sizeof(listaN), stdin);
    listaL[strlen(listaN)-1] = '\0';

    do{
        char *amigo = strtok(listaL, " ");
        malloc()
        
    }


    

}
