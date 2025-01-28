//FALTA TERMINAR: VERIFICAR SE ENTRA EM LOOP

#include <stdio.h>
#include <string.h>

int main(void){

    int x, y, a=0, b=0, erro=0;

    scanf("%d\n", &x);
    scanf("%d\n", &y);
    
    char mapa[y][x];

    for(int i=0; i<y; i++){
       
        fgets(mapa[i], sizeof(mapa[i])+1, stdin);
        
        printf("%s",mapa[i]);
        printf("\n");
    
    }

    
    while(mapa[a][b] != '*'){
        switch(mapa[a][b]){
            case '>':
                mapa[a][b] = 'h';
                do{
                    printf("%c", mapa[a][b]);
                    b++;  
                }while((mapa[a][b] == '.') && (b<x));   
                if(b>=x) erro=1;
                break;
            case '<':
                mapa[a][b] = 'h';
                do{
                    printf("%c", mapa[a][b]);
                    b--;
                }while((mapa[a][b] == '.') && (b>=0));
                if(b<0) erro=1;
                break;
            case '^':
                mapa[a][b] = 'h';
                do{
                    printf("%c", mapa[a][b]);
                    a--;
                }while((mapa[a][b] == '.') && (a>=0));
                if(a<0) erro=1;
                break;
            case 'v':
                mapa[a][b] = 'h';
                do{
                    printf("%c", mapa[a][b]);
                    a++;
                }while((mapa[a][b] == '.') &&(a<y));
                if(a>=y) erro=1;
                break;
            case 'h':
                printf("%c", mapa[a][b]);
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
