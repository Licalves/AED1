#include <stdio.h>

int main(void){

    int n;
    long long total=1;

    scanf("%d", &n);

    total = 1LL + (1ll*n*(n-1))/2 + (1LL*n*(n-1)*(n-2)*(n-3))/24;

    printf("%lld\n", total);
}
