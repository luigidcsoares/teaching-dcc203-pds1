#include <stdio.h>

#include "53_func.h"

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    while (n >= 0) {
        printf("%d\n", soma_primos(n));
        scanf("%d", &n);
    }

    return 0;
}
