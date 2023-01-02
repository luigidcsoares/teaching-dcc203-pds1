#include <stdio.h>

int main(int argc, char *argv[]) {
    int fibonacci[101];

    // Casos base: fib(0) = 0 e fib(1) = 1
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i < 101; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    int n;
    scanf("%d", &n);

    while (n >= 0) {
        printf("%d\n", fibonacci[n]);
        scanf("%d", &n);
    }

    return 0;
}
