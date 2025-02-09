#include <stdio.h>

int main(void) {
    int n, m, c, chaves, keybase;

    scanf("%d", &n);

    for (int count = 0; count < n; count++) { 
        scanf("%d %d", &m, &c);  
        
        int hashtable[100][10] = {0}; 
        int casa[100] = {0}; 

        for (int i = 0; i < c; i++) {
            scanf("%d", &chaves);
            keybase = chaves % m;  
            
            hashtable[keybase][casa[keybase]] = chaves;
            casa[keybase]++;
        }

        for (int i = 0; i < m; i++) {
            printf("%d -> ", i);
            int k = 0;
            while (k < casa[i]) {  
                printf("%d -> ", hashtable[i][k]);
                k++;
            }
            printf("\\\n");  
        }

        if (count < n - 1) { 
            printf("\n");
        }
    }

    return 0;
}

