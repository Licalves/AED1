#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define MAX_NOME 51

typedef struct {
    char nome[MAX_NOME];
    double preco;
} Produto;

int main() {
    int N, M, P, quantidade;
    char nomeProduto[MAX_NOME];
    
    scanf("%d", &N);
    
    while (N--) {
        scanf("%d", &M);
        Produto produtos[MAX_PRODUTOS];
        
        for (int i = 0; i < M; i++) {
            scanf("%s %lf", produtos[i].nome, &produtos[i].preco);
        }
        
        scanf("%d", &P);
        double total = 0.0;
        
        for (int i = 0; i < P; i++) {
            scanf("%s %d", nomeProduto, &quantidade);
            for (int j = 0; j < M; j++) {
                if (strcmp(produtos[j].nome, nomeProduto) == 0) {
                    total += produtos[j].preco * quantidade;
                    break;
                }
            }
        }
        
        printf("R$ %.2f\n", total);
    }
    
    return 0;
}
