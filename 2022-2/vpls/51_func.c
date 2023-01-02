#include "51_func.h"

int fibonacci(int n) {
    if (n == 0) return 0;

    int fib_prev = 0;
    int fib = 1;

    for (int i = 2; i <= n; i++) {
        int tmp = fib + fib_prev;
        fib_prev = fib;
        fib = tmp;
    }

    return fib;
}
