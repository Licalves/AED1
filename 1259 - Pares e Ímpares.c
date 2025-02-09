#include <stdio.h>

void quickSort(int arr[], int low, int high, int ordem) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if ((ordem == 1 && arr[j] <= pivot) || (ordem == -1 && arr[j] >= pivot)) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        
        int pi = i + 1;

        quickSort(arr, low, pi - 1, ordem);
        quickSort(arr, pi + 1, high, ordem);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int pares[100000], impares[100000];
    int contador_pares = 0, contador_impares = 0;
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        if (num % 2 == 0) {
            pares[contador_pares++] = num;
        } else {
            impares[contador_impares++] = num;
        }
    }

    quickSort(pares, 0, contador_pares - 1, 1); 
    quickSort(impares, 0, contador_impares - 1, -1);

    for (int i = 0; i < contador_pares; i++) {
        printf("%d\n", pares[i]);
    }

    for (int i = 0; i < contador_impares; i++) {
        printf("%d\n", impares[i]);
    }

    return 0;
}
