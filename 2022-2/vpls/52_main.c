#include <stdio.h>
#include <stdbool.h>
#include "52_func.h"

int main(int argc, char *argv[]) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (eh_triangulo(a, b, c)) {
        switch (tipo_triangulo(a, b, c)) {
            case 0:
                printf("Escaleno\n");
                break;
            case 1:
                printf("Isósceles\n");
                break;
            case 2:
                printf("Equilátero\n");
                break;
        }
    } else {
        printf("Não forma triângulo\n");
    }

    return 0;
}
