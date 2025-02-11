#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int verificaPermutacao(int n, int saida[]) {
    int pilha[MAX], topo = -1, proximo = 1;
    
    for (int i = 0; i < n; i++) {
        while (proximo <= saida[i]) {
            pilha[++topo] = proximo++;
        }
        if (pilha[topo] == saida[i]) {
            topo--;
        } else {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, saida[MAX];
    int primeiroCaso = 1;
    
    while (scanf("%d", &n) && n != 0) {
        if (!primeiroCaso) printf("\n");
        primeiroCaso = 0;
        
        while (1) {
            scanf("%d", &saida[0]);
            if (saida[0] == 0) break;
            
            for (int i = 1; i < n; i++) {
                scanf("%d", &saida[i]);
            }
            
            if (verificaPermutacao(n, saida)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        printf("\n");
    }
    return 0;
}
