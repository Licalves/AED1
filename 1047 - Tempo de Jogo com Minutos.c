#include <stdio.h>

int main(void){

    int H1, M1, H2, M2, horas=0, minutos=0;

    scanf("%d", &H1);
    scanf("%d", &M1);
    scanf("%d", &H2);
    scanf("%d", &M2);

    while((H1 != H2)||(M1 != M2)){
        if(M1 == 59){
            M1 = 0;
            if(H1 == 23){
                H1 = 0;
            } else {
                H1++;
            }
            if(minutos == 59){
                minutos = 0;
                horas++;
            } else {
                minutos++;
            }
        } else {
            M1++;
            if(minutos == 59){
                minutos = 0;
                horas++;
            } else {
                minutos++;
            }
        }
    }

    

    if((minutos + horas) == 0){
        horas = 24;
    }
    
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);

    return 0;
}
