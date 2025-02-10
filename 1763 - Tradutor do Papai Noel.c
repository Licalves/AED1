#include <stdio.h>
#include <string.h>

typedef struct {
    char pais[30];
    char mensagem[50];
} Saudacao;

int main() {
    Saudacao lista[] = {
        {"brasil", "Feliz Natal!"},
        {"alemanha", "Frohliche Weihnachten!"},
        {"austria", "Frohe Weihnacht!"},
        {"coreia", "Chuk Sung Tan!"},
        {"espanha", "Feliz Navidad!"},
        {"grecia", "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra", "Merry Christmas!"},
        {"australia", "Merry Christmas!"},
        {"portugal", "Feliz Natal!"},
        {"suecia", "God Jul!"},
        {"turquia", "Mutlu Noeller"},
        {"argentina", "Feliz Navidad!"},
        {"chile", "Feliz Navidad!"},
        {"mexico", "Feliz Navidad!"},
        {"antardida", "Merry Christmas!"},
        {"canada", "Merry Christmas!"},
        {"irlanda", "Nollaig Shona Dhuit!"},
        {"belgica", "Zalig Kerstfeest!"},
        {"italia", "Buon Natale!"},
        {"libia", "Buon Natale!"},
        {"siria", "Milad Mubarak!"},
        {"marrocos", "Milad Mubarak!"},
        {"japao", "Merii Kurisumasu!"}
    };
    
    int num_paises = sizeof(lista) / sizeof(lista[0]);
    char entrada[30];
    
    while (scanf("%s", entrada) != EOF) {
        int encontrado = 0;
        
        for (int i = 0; i < num_paises; i++) {
            if (strcmp(entrada, lista[i].pais) == 0) {
                printf("%s\n", lista[i].mensagem);
                encontrado = 1;
                break;
            }
        }
        
        if (!encontrado) {
            printf("--- NOT FOUND ---\n");
        }
    }
    
    return 0;
}
