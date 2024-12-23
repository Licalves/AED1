//DÚVIDA NESSE CÓDIGO, FALAR COM PROFESSOR NAS VOLTAS AS AULAS

#include <stdio.h>

void dfs(int v[][100], int n, int segmento, int visitado[]){
    visitado[segmento] = 1;

    for(int i=0; i<n; i++){
        if(v[segmento][i] == 1 && visitado[i] == 0)
        dfs(v, n, i, visitado);
    }
}

int main(void){

    int n, l, x, y;

    scanf("%d", &n);
    scanf("%d", &l);

    int v[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
        v[i][j] = 0;
        }
    }   
     
    for(int k=0; k<l; k++){
        scanf("%d", &x);
        scanf("%d", &y);
        v[x-1][y-1] = 1;
        v[y-1][x-1] = 1;
    }

    int visitado[n];
    for(int i=0; i<n; i++){
        visitado[i] = 0;
    }
    
    dfs(v, n, 0, visitado);

    int completo=1;
    for(int i=0; i<n; i++){
        if(visitado[i] == 0){
            completo = 0;
            break;
        }
    }

    if(completo == 1){
        printf("COMPLETO\n");
    } else {
        printf("INCOMPLETO\n");
    }


    return 0;
}
