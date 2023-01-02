#include <stdio.h>

// "define" é uma macro que nos permite dar nome a um pedaço de código.
// Macros são preprocessadas antes do início da compilação. Nesta etapa
// de preprocessamento, o código é escaneado e toda ocorrência do nome
// utilizado na macro é substituída pelo valor correspondente. No nosso
// caso, toda ocorrência de "N" será substituída pelo valor 10.
//
// Como, em tese, o tamanho de um array deve sempre ser uma expressão
// constante, vamos utilizar a macro define para dar um nome a este tamanho.
#define N 10

int main(int argc, char *argv[]) {
    int X[N];
    for (int i = 0; i < N; i++) scanf("%d", &X[i]);

    for (int i = 0; i < N/2; i++) {
        int tmp = X[i];
        X[i] = X[N - i - 1];
        X[N - i - 1] = tmp;
    }

    for (int i = 0; i < N; i++) printf("%d ", X[i]);
    printf("\n");

    return 0;
}
