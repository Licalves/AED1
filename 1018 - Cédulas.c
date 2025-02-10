#include <stdio.h>
 
int main() {
 
    int x, n50=0, n20=0, n10=0, n5=0, n2=0, n1=0, valor;
    int ncem = 0;
    scanf("%d", &valor);
    
    x = valor;
    
    while(x>0){
        
        if(x >= 100){
            x -= 100;
            ncem++;
            continue;
        }
        if(x >= 50){
            x -= 50;
            n50++;
            continue;
        }
        if(x >= 20){
            x -= 20;
            n20++;
            continue;
        }
        if(x >= 10){
            x -= 10;
            n10++;
            continue;
        }
        if(x >= 5){
            x -= 5;
            n5++;
            continue;
        }
        if(x >= 2){
            x -= 2;
            n2++;
            continue;
        }
        if(x >= 1){
            x -= 1;
            n1++;
            continue;
        }
    }
    
    printf("%d\n", valor);
    printf("%d nota(s) de R$ 100,00\n", ncem);
    printf("%d nota(s) de R$ 50,00\n", n50);
    printf("%d nota(s) de R$ 20,00\n", n20);
    printf("%d nota(s) de R$ 10,00\n", n10);
    printf("%d nota(s) de R$ 5,00\n", n5);
    printf("%d nota(s) de R$ 2,00\n", n2);
    printf("%d nota(s) de R$ 1,00\n", n1);
    
 
    return 0;
}
