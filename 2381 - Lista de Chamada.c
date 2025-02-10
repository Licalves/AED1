#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define MAX_LEN 20

int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    char alunos[MAX_N][MAX_LEN + 1];
    char *ptrs[MAX_N];

    for (int i = 0; i < N; i++) {
        scanf("%s", alunos[i]);
        ptrs[i] = alunos[i];
    }
  
    qsort(ptrs, N, sizeof(char *), comparar);

    printf("%s\n", ptrs[K - 1]);

    return 0;
}
