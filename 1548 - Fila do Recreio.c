#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        int M;
        scanf("%d", &M);
        
        int notas[M];
        for (int i = 0; i < M; i++) {
            scanf("%d", &notas[i]);
        }
        
        int notas_ordenadas[M];
        for (int i = 0; i < M; i++) {
            notas_ordenadas[i] = notas[i];
        }
        
        // Ordenar as notas em ordem decrescente
        for (int i = 0; i < M - 1; i++) {
            for (int j = i + 1; j < M; j++) {
                if (notas_ordenadas[i] < notas_ordenadas[j]) {
                    int temp = notas_ordenadas[i];
                    notas_ordenadas[i] = notas_ordenadas[j];
                    notas_ordenadas[j] = temp;
                }
            }
        }
        
        // Contar quantos alunos não mudaram de lugar
        int count = 0;
        for (int i = 0; i < M; i++) {
            if (notas[i] == notas_ordenadas[i]) {
                count++;
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}
