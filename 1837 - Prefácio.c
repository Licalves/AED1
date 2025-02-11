#include <stdio.h>

int main(){
    int a, b, q, r;

    scanf("%d %d", &a, &b);

    q = a / b; 
    r = a - b * q;

    if(r < 0){
        r = r + abs(b);
    }
    q = (a - r) / b;
    
    printf("%d %d\n", q, r);
    return 0;
}
