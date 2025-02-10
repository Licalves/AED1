#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);
        int *alturas = (int*)malloc(N * sizeof(int));
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &alturas[i]);
        }
        
        qsort(alturas, N, sizeof(int), comparar);
        
        for (int i = 0; i < N; i++) {
            if (i > 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");
        
        free(alturas);
    }
    return 0;
}
