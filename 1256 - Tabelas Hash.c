//FALTA TERMINAR, PENSAR NOQUE FAZER SOBRE O N 

#include <stdio.h>

typedef struct cel{
    int chave;
    struct cel *seg;
} celula;

int main(void){
    int n, m, c, chaves, keybase, count=0;
    
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &c);
    
    int hashtable[100][10], casa[100];
    
    while(count<n){
        
        for(int i=0; i<100; i++){
        casa[i] = 0;
            for(int j=0; j<10; j++){
            hashtable[i][j] = 0;
            }
        }

        for(int i=0; i<c; i++){
            scanf("%d", &chaves);
            keybase = chaves%13;
        
            hashtable[keybase][casa[keybase]] = chaves;
            casa[keybase] += 1;
        }
        
        int k;
        for(int i=0; i<m; i++){
            k=0;
            printf("%d -> ", i);
            while(hashtable[i][k] != 0){
                printf("%d -> ", hashtable[i][k]);
                k++;
            }
            printf("\\");
            printf("\n");
        }
        
        printf("\n");
        n++;
    }
    
    

    return 0;
}
