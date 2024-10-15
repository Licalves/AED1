#include <stdio.h>
 
int main() {
 
    int idade, anos=0, meses=0, dias=0;
    
    scanf("%d", &idade);
    
    dias = idade;
    
    if(dias >= 365){
        while(dias >= 365){
        anos++;
        dias -= 365;
      }
    }
    if(dias >= 30){
        while(dias >= 30){
        meses++;
        dias -= 30;
      }
    }
    
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);
 
    return 0;
}
