#include <stdio.h>
#include <string.h>

typedef struct {
    int ascii;
    int freq;
} CharFreq;

void sort(CharFreq arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].freq > arr[j + 1].freq || (arr[j].freq == arr[j + 1].freq && arr[j].ascii < arr[j + 1].ascii)) {
                CharFreq temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    char line[1001];
    int catraca=0, flag=0;
    
    while (fgets(line, sizeof(line), stdin)) {
        
        int freq[256] = {0};
        int len = strlen(line);
        if (line[len - 1] == '\n') line[len - 1] = '\0';
        
        if(catraca){
            printf("\n");
        }
        catraca=1;
        
        for (int i = 0; line[i] != '\0'; i++) {
            freq[(unsigned char) line[i]]++;
        }
        
        CharFreq chars[256];
        int count = 0;
        
        for (int i = 0; i < 256; i++) {
            if (freq[i] > 0) {
                chars[count].ascii = i;
                chars[count].freq = freq[i];
                count++;
            }
        }
        
        sort(chars, count);
        
        for (int i = 0; i < count; i++) {
            printf("%d %d\n", chars[i].ascii, chars[i].freq);
        }
    }
    
    return 0;
}
