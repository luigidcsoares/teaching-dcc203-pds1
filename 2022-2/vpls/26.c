#include <stdio.h>

int main(int argc, char *argv[]) {
    float valor_produto;
    scanf("%f", &valor_produto);

    char estado;
    scanf(" %c", &estado);

    switch (estado) {
        case 'M':
        case 'm':
            printf("%.2f\n", valor_produto * 1.07);
            float taxa = 0.07;
            break;
        case 'S':
        case 's':
            printf("%.2f\n", valor_produto * 1.12);
            break;
        case 'R':
        case 'r':
            printf("%.2f\n", valor_produto * 1.15);
            break;
        case 'B':
        case 'b':
            printf("%.2f\n", valor_produto * 1.08);
            break;
        default:
            printf("Estado inválido!");
    }

    return 0;
}
