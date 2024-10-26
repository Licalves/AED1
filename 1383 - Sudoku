#include <stdio.h>
#include <ctype.h>

int verificaColuna(int v[9][9], int a, int b);

int verificaLinha(int v[9][9], int a, int b);

int verificaBloco(int v[9][9]);

int main() {

    int matriz[9][9], n, k=1;


    //Lendo a quantidade de matrizes.
    do { 
        scanf("%d", &n);
    } while((n <= 0)&&(isdigit(n) == 0));

    int vetor[n];

    while(k <= n){

        int count=0;

        //Lendo a matriz de instância k.
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                scanf("%d", &matriz[i][j]);
            }
        }
        

        //Verificação de cada elemento do sudoku com sua respectiva linha e coluna.
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if((verificaColuna(matriz, i, j)!=1)||(verificaLinha(matriz, i, j)!=1)){
                    count++;
                }
            }
        }

        //Verificação dos blocos 3x3 do sudoku
        if(verificaBloco(matriz)!=1){
            count++;
        }

        //Caso não tenha algum valor errado, então o sudoku é valido.
        if(count == 0){
            vetor[k-1] = 1;
        } else {
            vetor[k-1] = 0;
        }

        //Passando para a próxima instância.
        k++;

    }

    //Printando as instâncias.
    for(int i=0; i<n; i++){
        printf("Instancia %d\n", i+1);
        if(vetor[i] == 1){
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}

int verificaLinha(int v[9][9], int a, int b){
    int verifica=0;

    
    for(int j=0; j<9; j++){
        if(b != j){
            if(v[a][b] == v[a][j]){
               verifica++;
            }
        }

    }
    
    if(verifica == 0){
        return 1;
    } else {
        return 0;
    }
}

int verificaColuna(int v[9][9], int a, int b){
    int verifica=0;

    for(int j=0; j<9; j++){
        if(a != j){
            if(v[a][b] == v[j][b]){
               verifica++;
            }
        }

    }

    if(verifica == 0){
        return 1;
    } else {
        return 0;
    }

}

int verificaBloco(int v[9][9]){
    int count=0;
    for(int countA=0; countA<3; countA++){
        for(int countB=0; countB<3; countB++){
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        for(int k=0; k<3; k++){
                            for(int h=0; h<3; h++){
                                if((i!=k)||(j!=h)){
                                   if(v[i+(3*countA)][j+(3*countB)] == v[k+(3*countA)][h+(3*countB)]){
                                     count++;
                                   }
                                }
                            }
                        }
                    }
                }
            }
        }
       
    
    if(count == 0){
        return 1;
    } else {
        return 0;
    }

}




