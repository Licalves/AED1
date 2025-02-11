#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 10000
#define MAX_M 30000

typedef struct {
    int u, v;
} Aresta;

Aresta arestas[MAX_M];
int inicio[MAX_N + 1], proximo[MAX_M], lista[MAX_M], idx;
bool visitado[MAX_N + 1], pilha[MAX_N + 1];

void adicionar_aresta(int u, int v) {
    lista[idx] = v;
    proximo[idx] = inicio[u];
    inicio[u] = idx++;
}

bool dfs(int u) {
    visitado[u] = true;
    pilha[u] = true;
    for (int i = inicio[u]; i != -1; i = proximo[i]) {
        int v = lista[i];
        if (!visitado[v]) {
            if (dfs(v)) return true;
        } else if (pilha[v]) {
            return true;
        }
    }
    pilha[u] = false;
    return false;
}

bool tem_ciclo(int n) {
    for (int i = 1; i <= n; i++) {
        visitado[i] = false;
        pilha[i] = false;
    }
    for (int i = 1; i <= n; i++) {
        if (!visitado[i] && dfs(i)) return true;
    }
    return false;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        idx = 0;
        for (int i = 1; i <= n; i++) inicio[i] = -1;
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adicionar_aresta(a, b);
        }
        printf(tem_ciclo(n) ? "SIM\n" : "NAO\n");
    }
    return 0;
}
