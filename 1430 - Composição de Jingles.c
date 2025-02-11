#include <stdio.h>
#include <string.h>

float get_duration(char note) {
    switch (note) {
        case 'W': return 1.0;
        case 'H': return 0.5;
        case 'Q': return 0.25;
        case 'E': return 0.125;
        case 'S': return 0.0625;
        case 'T': return 0.03125;
        case 'X': return 0.015625;
        default: return 0.0;
    }
}

int count_correct_measures(const char *composition) {
    int correct_count = 0;
    float sum = 0.0;
    
    for (int i = 1; composition[i] != '\0'; i++) {
        if (composition[i] == '/') {
            if (sum == 1.0) correct_count++;
            sum = 0.0;
        } else {
            sum += get_duration(composition[i]);
        }
    }
    
    return correct_count;
}

int main() {
    char composition[205];
    
    while (1) {
        scanf("%s", composition);
        if (composition[0] == '*') break;
        printf("%d\n", count_correct_measures(composition));
    }
    
    return 0;
}
