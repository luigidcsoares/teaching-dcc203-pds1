#include "01_ordenacao.h"

void swap(int *A, unsigned i, unsigned j) {
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}

bool sorted(int *A, int n) {
    for (int i = 1; i < n; i++) {
        if (A[i - 1] > A[i]) return false;
    }
    return true;
}

void bubblesort(int *A, int n) {
    for (int i = 0; i < n; i++) {
        bool swapped = false;

        // Cada vez que passamos pelo arranjo, colocamos o maior elemento
        // (dentre os restantes) na posição correta. Em outras palavras:
        //
        // quando i = 0, percorremos o arranjo inteiro e colocamos o maior
        // elemento na última posição (n - 1).
        //
        // quando i = 1, percorremos o arranjo até a penúltima posição e
        // colocamos o segundo maior elemento na penúltima posição (n - 2).
        //
        // ... e assim sucessivamente.
        for (int j = 1; j < n - i; j++) {
            if (A[j - 1] > A[j]) {
                swap(A, j - 1, j);
                swapped = true;
            }
        }

        // Otimização: Se não houve nenhuma troca, o arranjo está
        // ordenado. Logo, não precisamos continuar o processo.
    }
}
