//ainda falta terminar esse exercício
//lista ponteiro strings

#define MAX 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lista {
    char nome[MAX];
    struct lista *seguinte;
};

void insere(char string[MAX], struct lista *p);
void juntaLista(char string[MAX], struct lista *a, struct lista *b);

int main(void){

    struct lista *luiggy = malloc(sizeof(struct lista));
    struct lista *amigos = malloc(sizeof(struct lista));
    char *amigo, listaL[MAX], listaN[MAX], buscaAmg[MAX];

    luiggy->seguinte = NULL;
    amigos->seguinte = NULL;

    fgets(listaL, sizeof(listaL), stdin);
    listaL[strlen(listaL)-1] = '\0';

    fgets(listaN, sizeof(listaN), stdin);
    listaN[strlen(listaN)-1] = '\0';

    //separa os amigos atuais de luiggy e os ordena na listaL
    amigo = strtok(listaL, " ");
    while(amigo != NULL) { 
        insere(amigo, luiggy);
        amigo = strtok(NULL, " ");
    }

    //separa os amigos novos de luiggy e os ordena na listaN
    amigo = strtok(listaN, " ");
    while(amigo != NULL) {
        insere(amigo, amigos);
        amigo = strtok(NULL, " ");
    }


    fgets(buscaAmg, sizeof(buscaAmg), stdin);
    buscaAmg[strlen(buscaAmg)-1] = '\0';
    
    juntaLista(buscaAmg, luiggy, amigos);

}

//crie uma celula nova na lista
void insere(char string[MAX], struct lista *p){
    struct lista *novaN;
    novaN = malloc(sizeof(struct lista));
    strcpy(novaN->nome, string);
    novaN->seguinte = p->seguinte;
    p->seguinte = novaN;
}


//procura o nome do amigo na listaL e insere a listaN imediatamente antes desse nome
//caso 'nao' insere listaN depois de listaL
void juntaLista(char string[MAX], struct lista *a, struct lista *b){
    struct lista *p, *q, *nova;
    nova = malloc(sizeof(struct lista));
    p = a;
    q = a->seguinte;
    while(q != NULL && (strcmp(q->nome,string) != 0)){
        p = q;
        q = q->seguinte;
    }
    b->seguinte = q;
    p->seguinte = b;
}
