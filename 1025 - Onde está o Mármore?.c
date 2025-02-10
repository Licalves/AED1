#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int busca_binaria(int arr[], int tamanho, int alvo) {
    int inicio = 0, fim = tamanho - 1, meio, resultado = -1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        
        if (arr[meio] == alvo) {
            resultado = meio;  
            fim = meio - 1;  
        } else if (arr[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return resultado;
}

int main() {
    int n, q, caso = 1;
    
    while (1) {
        scanf("%d %d", &n, &q);
        if (n == 0 && q == 0) break;

        int marmores[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &marmores[i]);
        }

        qsort(marmores, n, sizeof(int), compare);

        printf("CASE# %d:\n", caso++);

        for (int i = 0; i < q; i++) {
            int consulta;
            scanf("%d", &consulta);

            int posicao = busca_binaria(marmores, n, consulta);

            if (posicao != -1) {
                printf("%d found at %d\n", consulta, posicao + 1);
            } else {
                printf("%d not found\n", consulta);
            }
        }
    }

    return 0;
}
