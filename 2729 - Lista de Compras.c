#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 1000
#define MAX_LEN 20

int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        char linha[MAX_ITENS * (MAX_LEN + 1)], *itens[MAX_ITENS];
        int count = 0;
        fgets(linha, sizeof(linha), stdin);
        char *token = strtok(linha, " \n");
        while (token) {
            int duplicado = 0;
            for (int j = 0; j < count; j++) {
                if (strcmp(itens[j], token) == 0) {
                    duplicado = 1;
                    break;
                }
            }
            if (!duplicado) {
                itens[count] = strdup(token);
                count++;
            }
            token = strtok(NULL, " \n");
        }
        qsort(itens, count, sizeof(char *), comparar);
        for (int j = 0; j < count; j++) {
            if (j > 0) printf(" ");
            printf("%s", itens[j]);
            free(itens[j]);
        }
        printf("\n");
    }
    return 0;
}
