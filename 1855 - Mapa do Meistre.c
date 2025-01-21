//FALTA TERMINAR: VERIFICAR SE ENTRA EM LOOP

#include <stdio.h>

int main(void){

    int x, y, a=0, b=0, erro=0;

    scanf("%d\n", &x);
    scanf("%d\n", &y);
    
    getchar();
    
    char mapa[x][y];

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            scanf("%c ", &mapa[i][j]);
        }
    }

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("%d", mapa[i][j]);
        }
        printf("\n");
    }

    while(mapa[a][b] != '*'){
        switch(mapa[a][b]){
            case '>':
                mapa[a][b] = x;
                while((mapa[a][b] == '.')&&(a<x)){
                    a++;  
                }   
                if(a>=x) erro=1;
                break;
            case '<':
                mapa[a][b] = x;
                while((mapa[a][b] == '.')&&(a>=0)){
                    a--;
                }
                if(a<0) erro=1;
                break;
            case '^':
                mapa[a][b] = x;
                while((mapa[a][b] == '.')&&(b>=y)){
                    b--;
                }
                if(b<0) erro=1;
                break;
            case 'v':
                mapa[a][b] = x;
                while((mapa[a][b] == '.')&&(b<y)){
                    b++;
                }
                if(b>=y) erro=1;
                break;
            case 'x':
                erro=1;
                break;
            
        }

        if(erro==1){
            printf("!\n");
            break; 
        }
    }

    if(erro != 1){
        printf("*");
    }
    
} 
