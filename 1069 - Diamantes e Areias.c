#include <stdio.h>
#include <string.h>

int contarDiamantes(char s[]);

int main() {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        char s[1001];
        scanf("%s", s);
        printf("%d\n", contarDiamantes(s));
    }
    
    return 0;
}

int contarDiamantes(char s[]) {
    int diamantes = 0;
    int count = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '<') {
            count++;
        } else if (s[i] == '>') {
            if (count > 0) {
                diamantes++;
                count--;
            }
        }
    }
    
    return dia
