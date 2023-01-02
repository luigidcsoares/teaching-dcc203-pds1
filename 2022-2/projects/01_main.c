#include <stdio.h>
#include "01_ordenacao.h"

// ===============================================
// =========== NÃO ALTERE ESTE ARQUIVO ===========
// ===============================================

void print_array(int *A, int n) {
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int A[100];

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    char test_case;
    scanf(" %c", &test_case);

    switch (test_case) {
        case 'b':
            bubblesort(A, n);
            print_array(A, n);
        case 's':
            printf("Está ordenado? %s\n", sorted(A, n) ? "Sim" : "Não");
            break;
        default:
            printf("Caso de teste inválido!");
    }

    return 0;
}
