#include <stdio.h>

int main() {
    int voltas, placas;
    scanf("%d %d", &voltas, &placas);
    
    int total_placas = voltas * placas;
    
    for (int i = 1; i <= 9; i++) {
        if (i > 1) printf(" ");
        printf("%d", (total_placas * i + 9) / 10);
    }
    
    printf("\n");
    return 0;
}
