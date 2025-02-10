#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

void identificar_estrutura(int operacoes[][2], int n) {
    int pilha[MAX], fila[MAX], heap[MAX];
    int topo = -1, frente = 0, tras = -1, tamanho = 0;
    int heap_size = 0;
    bool eh_pilha = true, eh_fila = true, eh_heap = true;

    for (int i = 0; i < n; i++) {
        int tipo = operacoes[i][0];
        int valor = operacoes[i][1];

        if (tipo == 1) { 
            pilha[++topo] = valor;
            fila[++tras] = valor;
            heap[heap_size++] = valor;
        } else { 
            if (topo < 0 || frente > tras || heap_size == 0) {
                printf("impossible\n");
                return;
            }
            
            if (eh_pilha) {
                if (pilha[topo--] != valor)
                    eh_pilha = false;
            }

            if (eh_fila) {
                if (fila[frente++] != valor)
                    eh_fila = false;
            }

            if (eh_heap) {
                int max_index = 0;
                for (int j = 1; j < heap_size; j++) {
                    if (heap[j] > heap[max_index])
                        max_index = j;
                }
                
                if (heap[max_index] != valor)
                    eh_heap = false;
                else {
                    heap[max_index] = heap[--heap_size];
                }
            }
        }
    }

    if (eh_pilha + eh_fila + eh_heap > 1)
        printf("not sure\n");
    else if (eh_pilha)
        printf("stack\n");
    else if (eh_fila)
        printf("queue\n");
    else if (eh_heap)
        printf("priority queue\n");
    else
        printf("impossible\n");
}

int main(void){
    int n;
    while (scanf("%d", &n) != EOF) {
        int operacoes[n][2];
        for (int i = 0; i < n; i++) {
            scanf("%d", &operacoes[i][0]);
            if (operacoes[i][0] == 1)
                scanf("%d", &operacoes[i][1]);
            else
                scanf("%d", &operacoes[i][1]);
        }
        identificar_estrutura(operacoes, n);
    }
    return 0;
}
