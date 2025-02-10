#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int temp[MAX_N];

long long merge_count(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    return inv_count;
}

long long count_inversions(int arr[], int left, int right) {
    if (left >= right) return 0;

    int mid = left + (right - left) / 2;
    long long inv_count = 0;

    inv_count += count_inversions(arr, left, mid);
    inv_count += count_inversions(arr, mid + 1, right);
    inv_count += merge_count(arr, left, mid, right);

    return inv_count;
}

int main() {
    int N;
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        int arr[MAX_N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        long long inversions = count_inversions(arr, 0, N - 1);
        if (inversions % 2 == 0) {
            printf("Carlos\n");
        } else {
            printf("Marcelo\n");
        }
    }
    return 0;
}
