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

    getchar();  

    for(int i=0; i<m; i++){
        scanf("%c", palavra);
        scanf("%d", &valor);
        getchar();
        insere(valor, palavra, &dics, &dict);
    }

    celula *p;
    int t=0;

    fgets(texto, sizeof(texto), stdin);

    for(int i=0; i<n; i++){
        total[i] = 0;
        
        while (1) {
            fgets(texto + strlen(texto), sizeof(texto) - strlen(texto), stdin);   
             if (strcmp(texto + strlen(texto) - 2, ".\n") == 0) {   
                texto[strlen(texto) - 2] = '\0';   
                break;  
            }
        }

        p = dics;

        while(p != NULL){
            if(strstr(texto, p->palavra)!=NULL){
                total[i] += p->valor;
            }
            p = p->seg;
        }
    }

    for(int i=0; i<n; i++){
        printf("%d\n", total[i]);
    }
}   
