#include <stdio.h>
#include <string.h>

int main(void){

    char n1[100];
    char n2[100];
    char n3[100];

    fgets(n1, sizeof(n1), stdin);
    n1[strlen(n1)-1]='\0';

    fgets(n2, sizeof(n2), stdin);
    n2[strlen(n2)-1]='\0';

    fgets(n3, sizeof(n3), stdin);
    n3[strlen(n3)-1]='\0';

    printf("%s%s%s\n", n1, n2, n3);
    printf("%s%s%s\n", n2, n3, n1);
    printf("%s%s%s\n", n3, n1, n2);
    
    for(int i=0; i<10; i++){
        if(n1[i] == '\0'){
            break;
        }
        printf("%c", n1[i]);
    }
    for(int i=0; i<10; i++){
        if(n2[i] == '\0'){
            break;
        }
        printf("%c", n2[i]);
    }
    for(int i=0; i<10; i++){
        if(n3[i] == '\0'){
            break;
        }
        printf("%c", n3[i]);
    }

    printf("\n");
}
