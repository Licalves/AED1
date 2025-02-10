#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

void simplificar(int *num, int *den) {
    if (*den < 0) { 
        *num *= -1;
        *den *= -1;
    }
    int divisor = mdc(abs(*num), abs(*den));
    *num /= divisor;
    *den /= divisor;
}

int main() {
    int n, n1, d1, n2, d2, num, den;
    char op;
    
    scanf("%d", &n);
    
    while (n--) {
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);

        if (op == '+') {
            num = n1 * d2 + n2 * d1;
            den = d1 * d2;
        } else if (op == '-') {
            num = n1 * d2 - n2 * d1;
            den = d1 * d2;
        } else if (op == '*') {
            num = n1 * n2;
            den = d1 * d2;
        } else if (op == '/') {
            num = n1 * d2;
            den = n2 * d1;
        }

        printf("%d/%d = ", num, den);
        simplificar(&num, &den);
        printf("%d/%d\n", num, den);
    }

    return 0;
}
