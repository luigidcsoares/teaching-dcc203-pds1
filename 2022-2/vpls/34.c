#include <stdio.h>

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    int fib_anterior = 0;
    int fib_atual = 1;

    for (int i = 1; i < n; i++) {
        int fib_proximo = fib_anterior + fib_atual;
        fib_anterior = fib_atual;
        fib_atual = fib_proximo;
    }

    printf("%d\n", fib_atual);
    return 0;
}
