#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    int valor;
    scanf("%d", &valor);

    int num_alg = 1;
    while (valor / (int) pow(10, num_alg) != 0) {
        num_alg++;
    }

    int inverso = 0;
    for (int i = 1; i <= num_alg; i++) {
        int algarismo = valor % 10;
        valor /= 10;
        inverso += algarismo * pow(10, num_alg - i);
    }

    printf("Valor invertido: %d\n", inverso);
    return 0;
}
