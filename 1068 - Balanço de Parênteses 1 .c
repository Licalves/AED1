#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int bemFormada(char s[]);

int main() {
    char expressao[MAX];
    
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        if (expressao[strlen(expressao) - 1] == '\n') {
            expressao[strlen(expressao) - 1] = '\0';
        }

        if (bemFormada(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}

int bemFormada(char s[]) {
    char pilha[MAX];
    int t = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            pilha[t++] = s[i];  
        } else if (s[i] == ')') {
            if (t == 0 || pilha[t - 1] != '(') {
                return 0;  
            }
            t--;  
        }
    }
    
    return t == 0;
}

