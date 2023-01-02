#include "91_vetor.h"

int soma(int *vetor, int n) {
    if (n == 0) return 0;
    return vetor[n - 1] + soma(vetor, n - 1);
}
