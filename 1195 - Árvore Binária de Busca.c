#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda, *direita;
} No;

No* novo_no(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return novo_no(valor);
    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else
        raiz->direita = inserir(raiz->direita, valor);
    return raiz;
}

void pre_ordem(No* raiz) {
    if (raiz) {
        printf("%d", raiz->valor);
        if (raiz->esquerda || raiz->direita) printf(" ");
        pre_ordem(raiz->esquerda);
        if (raiz->esquerda && raiz->direita) printf(" ");
        pre_ordem(raiz->direita);
    }
}

void em_ordem(No* raiz) {
    if (raiz) {
        em_ordem(raiz->esquerda);
        if (raiz->esquerda) printf(" ");
        printf("%d", raiz->valor);
        if (raiz->direita) printf(" ");
        em_ordem(raiz->direita);
    }
}

void pos_ordem(No* raiz) {
    if (raiz) {
        pos_ordem(raiz->esquerda);
        if (raiz->esquerda) printf(" ");
        pos_ordem(raiz->direita);
        if (raiz->direita) printf(" ");
        printf("%d", raiz->valor);
    }
}

void liberar_arvore(No* raiz) {
    if (raiz) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    int casos, n, valor, i, j;
    scanf("%d", &casos);
    for (i = 1; i <= casos; i++) {
        scanf("%d", &n);
        No* raiz = NULL;
        for (j = 0; j < n; j++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        printf("Case %d:\n", i);
        printf("Pre.: "); pre_ordem(raiz); printf("\n");
        printf("In..: "); em_ordem(raiz); printf("\n");
        printf("Post: "); pos_ordem(raiz); printf("\n\n");
        liberar_arvore(raiz);
    }
    return 0;
}
