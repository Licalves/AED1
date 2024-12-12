
//MERGESORT 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 400000

void Insercao(int n, int v[]){
    for(int i=1; i<n; i++){
        int x=v[i];
        for(int j=i-1; j>=0 && v[j] > x; j--){
            v[i+1] = v[j];
        }
        v[i+1] = x;
    }
}

int main(void){
    clock_t t;
    int vetor[MAX];

    srand(time(NULL));

    for(int i=20000; i<=MAX; i=i+20000){

        for(int j=0; j<MAX; j++){
        vetor[j] = rand()%MAX;
        }

        t = clock();
    Insercao(i, vetor);
    t = clock() - t;

    printf("\nTempo para vetor tamanho %d: %lf ms\n", i, ((double)t)/((CLOCKS_PER_SEC/1000)));

    }

    return 0;
}
