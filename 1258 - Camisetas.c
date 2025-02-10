#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 51
#define MAX_ENTRIES 60

typedef struct {
    char name[MAX_NAME];
    char color[10];
    char size;
} Shirt;

int compare(const void *a, const void *b) {
    Shirt *shirtA = (Shirt *)a;
    Shirt *shirtB = (Shirt *)b;
    
    int colorCmp = strcmp(shirtA->color, shirtB->color);
    if (colorCmp != 0) return colorCmp;
    
    int sizeCmp = shirtB->size - shirtA->size;
    if (sizeCmp != 0) return sizeCmp;
    
    return strcmp(shirtA->name, shirtB->name);
}

int main() {
    int N, first = 1;
    while (scanf("%d", &N) && N != 0) {
        if (!first) printf("\n");
        first = 0;
        
        Shirt shirts[MAX_ENTRIES];
        for (int i = 0; i < N; i++) {
            getchar(); 
            fgets(shirts[i].name, MAX_NAME, stdin);
            shirts[i].name[strcspn(shirts[i].name, "\n")] = 0;
            scanf("%s %c", shirts[i].color, &shirts[i].size);
        }
        
        qsort(shirts, N, sizeof(Shirt), compare);
        
        for (int i = 0; i < N; i++) {
            printf("%s %c %s\n", shirts[i].color, shirts[i].size, shirts[i].name);
        }
    }
    return 0;
}
