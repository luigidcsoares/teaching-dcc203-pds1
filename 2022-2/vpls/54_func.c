#include "54_func.h"

int subarranjo_maximo(int *A, int n) {
    // Implementação "ingênua" ou "força bruta":
    // checar todos os subarranjos a partir de cada índice.
    int max = 0;
    for (int i = 0; i < n; i++) {
        int soma = 0;
        for (int j = i; j < n; j++) {
            soma += A[j];
            max = soma > max ? soma : max;
        }
    }
    return max;
}

int subarranjo_maximo_alt(int *A, int n) {
    // Uma implementação mais eficiente:
    int max = 0;

    // Armazenamos a soma de um subarranjo, até que a soma
    // se torne negativa. Se a soma se tornar negativa, a
    // melhor solução seria um subarranjo vazio, então
    // recomeçamos a partir de um novo subarranjo.
    int soma_atual = 0;

    for (int i = 0; i < n; i++) {
        soma_atual += A[i];

        if (soma_atual < 0) {
            soma_atual = 0;
            continue;
        }

        if (soma_atual > max) {
            max = soma_atual;
        }
    }

    return max;
}
