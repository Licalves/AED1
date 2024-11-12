//preciso de 2 filas e dois valores, uma fila para a fila que já tem as pessoas, 
//outra fila para as pessoas que sairam dessa fila, os outros inteiros são para o 
//numero de pessoas na fila1 e dila2

#include <stdio.h>
#include <stdlib.h>

struct fila {
    int ident;
    struct fila *seguinte;
};

void insere(int n, struct fila *p);
void buscaRemove(int n, struct fila*p);
void printaFila(struct fila *p);

int main(void){

    int qnt1, qnt2, temp;
    struct fila *p1 = malloc(sizeof(struct fila));

    //quantidade de pessoas na fila
    scanf("%d", &qnt1);

    //criando a lista com os indentificadores
    for(int i=0; i<qnt1; i++){
        scanf("%d", &temp);
        insere(temp, p1);
    }

    //quantidade de pessoas que sairam da fila
    scanf("%d", &qnt2);

    //tirando da fila as pessoas que sairam da fila
    for(int i=0; i<qnt2; i++){
        scanf("%d", &temp);
        buscaRemove(temp, p1);
    }

    //printando a fila
    printaFila(p1);

}

void insere(int n, struct fila *p){
    struct fila *nova, *temp;
    nova = malloc(sizeof(struct fila));
    nova->seguinte = NULL;
    nova->ident = n;

    temp = p;
    while(temp->seguinte != NULL){
        temp = temp->seguinte;
    }
    temp->seguinte = nova;
}

void buscaRemove(int n, struct fila*p){
    struct fila *a, *b;
    a = p;
    b = p->seguinte;
    while(b != NULL && b->ident != n){
        a = b;
        b = b->seguinte;
    }

    if(b != NULL){
        a->seguinte = b->seguinte;
        free(b);
    }

}

void printaFila(struct fila *p){
    struct fila *q;
    int primeiro = 1;
    for(q = p->seguinte; q != NULL; q = q->seguinte){
        if(primeiro){
            printf("%d", q->ident);
            primeiro = 0;
        } else {
            printf(" %d", q->ident);
        }
    }
    printf("\n");
}
