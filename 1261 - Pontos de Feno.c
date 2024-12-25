//TERMINAR AINDA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    int valor;
    char palavra[16];
    struct cel *seg;
} celula;

void insere(int valor, char palavra[16], celula **es, celula **et){
    celula *nova;
    nova = malloc(sizeof(celula));
    strcpy(nova->palavra, palavra);
    nova->valor = valor;
    if(*et == NULL) *es = *et = nova;
    (*et)->seg = nova;
    *et = nova;
}

int main(void){

    int m, n, valor;
    char palavra[16], texto[10000];

    celula *dics, *dict;

    scanf("%d", &m);
    scanf("%d", &n);

    int total[n];

    for(int i=0; i<m; i++){
        scanf("%c", palavra);
        scanf("%d", &valor);
        insere(valor, palavra, &dics, &dict);
    }

    celula *p;
    p = dics;

    for(int i=0; i<n; i++){
        fgets(texto, sizeof(texto), stdin);
        for(int j=0; j<m; j++){
            strcspn()
        }

    }
}   
