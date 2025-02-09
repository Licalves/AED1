#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int valor;
    struct cell* proximo;
} Cell;

void enfileirar(Cell** frente, Cell** tras, int valor) {
    Cell* novo = (Cell*) malloc(sizeof(Cell));
    novo->valor = valor;
    novo->proximo = NULL;
    
    if (*frente == NULL) {
        *frente = novo;
        *tras = novo;
    } else {
        (*tras)->proximo = novo;
        *tras = novo;
    }
}

int desenfileirar(Cell** frente) {
    if (*frente == NULL) {
        return -1;
    }
    
    Cell* temp = *frente;
    int valor = temp->valor;
    *frente = (*frente)->proximo;
    free(temp);
    
    return valor;
}

int fila_vazia(Cell* frente) {
    return frente == NULL;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        
        if (n == 0) break;

        Cell* frente = NULL;
        Cell* tras = NULL;

        for (int i = 1; i <= n; i++) {
            enfileirar(&frente, &tras, i);
        }

        printf("Discarded cards: ");
        int primeiro = 1;

        while (n > 1) {
            int cartaDescartada = desenfileirar(&frente); // Descartar carta do topo
            if (!primeiro) {
                printf(", ");
            }
            if (cartaDescartada != -1) {
                printf("%d", cartaDescartada);
                primeiro = 0;
            }
            
            int cartaParaBase = desenfileirar(&frente); // Mover carta para a base
            if (cartaParaBase != -1) {
                enfileirar(&frente, &tras, cartaParaBase);
            }
            n--; // Reduzir o número de cartas restantes
        }

        printf("\nRemaining card: %d\n", desenfileirar(&frente));
    }

    return 0;
}
