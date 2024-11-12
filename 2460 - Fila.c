//preciso de 2 filas e dois valores, uma fila para a fila que já tem as pessoas, 
//outra fila para as pessoas que sairam dessa fila, os outros inteiros são para o 
//numero de pessoas na fila1 e dila2

#include <stdio.h>
#include <stdlib.h>

struct fila {
    int ident;
    struct fila *seguinte;
};

void insere(int n, struct fila **es, struct fila **et);
void buscaRemove(int n, struct fila **es, struct fila **et);
void printaFila(struct fila *p);

int main(void){

    int qnt1, qnt2, temp;
    struct fila *s=NULL, *t=NULL;

    //quantidade de pessoas na fila
    scanf("%d", &qnt1);

    //criando a lista com os indentificadores
    for(int i=0; i<qnt1; i++){
        scanf("%d", &temp);
        insere(temp, &s, &t);
    }

    //quantidade de pessoas que sairam da fila
    scanf("%d", &qnt2);

    //tirando da fila as pessoas que sairam da fila
    for(int i=0; i<qnt2; i++){
        scanf("%d", &temp);
        buscaRemove(temp, &s, &t);
    }

    //printando a fila
    printaFila(s);

    return 0;

}

void insere(int n, struct fila **es, struct fila **et){
    struct fila *nova;
    nova = malloc(sizeof(struct fila));
    nova->ident = n;
    nova->seguinte = NULL;
    if(*et == NULL){
        *et = *es = nova;
    } else {
        (*et)->seguinte = nova;
        *et = nova;
    }

}

void buscaRemove(int n, struct fila **es, struct fila **et){
    struct fila *p = *es, *anterior=NULL;

    while(p != NULL && p->ident != n){
        anterior = p;
        p = p->seguinte;
    }

    if(p != NULL){
        if(anterior == NULL){
            *es = p->seguinte;
            if(*es == NULL){
                *et = NULL;
            }
    } else {
        anterior->seguinte = p->seguinte;
        if(p == *et){
            *et = anterior;
        }
    }
        free(p);
    }
}

void printaFila(struct fila *p){
    struct fila *q = p;
    int primeiro = 1;
    while( p != NULL){
        if(primeiro){
          printf("%d", p->ident);
          primeiro = 0;
        } else {
            printf(" %d", p->ident);
        }

        p = p->seguinte;
    }
    printf("\n");
}
