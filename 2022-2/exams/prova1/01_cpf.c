#include <stdio.h>
int main(int argc, char *argv[]) {
    long int cpf;
    scanf("%ld", &cpf);

    long int cpf_backup = cpf;
    int soma = 0;

    for (int peso = 2; peso <= 10; peso++) {
        int digito = cpf % 10;
        soma += peso * digito;
        cpf /= 10;
    }

    int dezena = soma % 11 <= 1 ? 0 : 11 - (soma % 11);

    cpf = cpf_backup;
    soma = dezena * 2;

    for (int peso = 3; peso <= 11; peso++) {
        int digito = cpf % 10;
        soma += peso * digito;
        cpf /= 10;
    }

    int unidade = soma % 11 <= 1 ? 0 : 11 - (soma % 11);
    printf("%d%d\n", dezena, unidade);

    return 0;
}
