
//MERGESORT 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 400000

int Separa(int p, int r, int v[]){
    int t;
    int c = v[r];
    int j = p;
    for(int k=p; k<r; k++){
        if(v[k] <= c){
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
        v[r] =v[j]; 
        v[j] = c;
        return j;
    }
}

void Quicksort(int p, int r, int v[]){
    int j;
    if(p<r){
        j = Separa(p, r , v);
        Quicksort(p, j-1, v);
        Quicksort(j+1, r, v);
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
    Quicksort(0, i, vetor);
    t = clock() - t;

    printf("\nTempo para vetor tamanho %d: %lf ms\n", i, ((double)t)/((CLOCKS_PER_SEC/1000)));

    }

    return 0;
}
