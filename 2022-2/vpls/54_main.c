#include <stdio.h>

#include "54_func.h"

int main(int argc, char *argv[]) {
    int A[10];

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("%d\n", subarranjo_maximo(A, n));
    /* printf("%d\n", subarranjo_maximo_alt(A, n)); */

    return 0;
}
