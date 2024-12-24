#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel{
    char nome[12];
    struct cel *seg;
} celula;

//função que insere nós na fila circular
void Insere(char name[12], celula **eprimeiro, celula **eultimo){
    celula *nova;
    nova = malloc(sizeof(celula));
    strcpy(nova->nome, name);
    nova->seg = *eprimeiro;
    if(*eultimo == NULL) *eultimo = *eprimeiro = nova;
    else {
        (*eultimo)->seg = nova;
        *eultimo = nova;
    }

}

int main(void){

    celula *primeiro, *ultimo, *p;
    primeiro = ultimo = NULL;
    int n;
    float l, q;
    char nome[12];

    scanf("%d", &n);
    scanf("%f", &l);
    scanf("%f", &q);

    getchar();

    for(int i=0; i<n; i++){
        scanf("%s", nome);
        Insere(nome, &primeiro, &ultimo);
    };

    p = primeiro;
    while(l > q){
        l -= q;
        p = p->seg;  
    }

    printf("%s %0.1f\n", p->nome, l);

    
}
