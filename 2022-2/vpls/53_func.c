#include "53_func.h"

#include <math.h>

bool eh_primo(int p) {
    // Não consideramos 1 primo, e nenhum múltiplo de 2
    // além do próprio 2 é primo.
    if (p == 1 || (p % 2 == 0 && p != 2)) {
        return false;
    }

    // Se não é divisível por 2, não é divisível por
    // nenhum múltiplo de 2. Então, só precisamos testar
    // os ímpares agora.
    for (int d = 3; d <= sqrt(p); d += 2) {
        if (p % d == 0) {
            return false;
        }
    }

    return true;
}

int soma_primos(int n) {
    int p = 1;
    int soma = 0;
    for (int i = 0; i < n; i++) {
        while (!eh_primo(p)) {
            p++;
        }
        soma += p;
        p++;
    }
    return soma;
}
