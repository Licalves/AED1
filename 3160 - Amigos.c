
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
void imprimeLista(struct lista *p);

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

    //imprime a lista apos a adição dos novos amigos
    imprimeLista(luiggy);

}

//crie uma celula nova na lista
void insere(char string[MAX], struct lista *p){
    struct lista *novaN, *temp;
    novaN = malloc(sizeof(struct lista));
    strcpy(novaN->nome, string);
    novaN->seguinte = NULL;
    
    temp = p;
    while(temp->seguinte != NULL){
        temp = temp->seguinte;
    }
    temp->seguinte = novaN;
}


//procura o nome do amigo na listaL e insere a listaN imediatamente antes desse nome
//caso 'nao' insere listaN depois de listaL
void juntaLista(char string[MAX], struct lista *a, struct lista *b){
    struct lista *p, *q;
    
    if(strcmp(string, "nao") == 0){
            p = a;

        while(p->seguinte != NULL){
            p = p->seguinte;
        }
        p->seguinte = b->seguinte;
        return;
    }

    p = a;
    q = a->seguinte;
    while (q != NULL && strcmp(q->nome, string) != 0){
        p = q;
        q = q->seguinte;
    }

    if(q != NULL){
        p->seguinte = b->seguinte;
        while(b->seguinte != NULL){
            b = b->seguinte;
        }
        b->seguinte = q;
    }
}

void imprimeLista(struct lista *p){
    struct lista *q;
    int primeiro=1;
    for(q = p->seguinte; q != NULL; q = q->seguinte){
        if(primeiro){
            printf("%s", q->nome);
            primeiro = 0;
        } else {
            printf(" %s", q->nome);
        }
    }
    printf("\n");
}
