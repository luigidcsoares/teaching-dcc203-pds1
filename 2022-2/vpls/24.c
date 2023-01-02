#include <stdio.h>

int main(int argc, char *argv[]) {
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);

    int menor = num1;
    int meio = num2;
    int maior = num3;

    // Primeiro, vamor encontrar o menor valor entre os três
    if (menor > meio) {
        // Encontramos um 'novo' menor e um 'novo' meio, então devemos
        // atualizá-los. Chamamos essa operação de swap (troca). Para
        // isso, precisamos de armazenar um dos valores temporariamente.
        int tmp = menor;
        menor = meio;
        meio = tmp;
    }

    // Ainda precisamos comparar em relação ao 'maior'
    if (menor > maior) {
        int tmp = menor;
        menor = maior;
        maior = tmp;
    }

    // Já encontramos qual dos três é o menor valor, vamos agora
    // repetir o processo com os dois que restaram
    if (meio > maior) {
        int tmp = meio;
        meio = maior;
        maior = tmp;
    }

    printf("%d, %d, %d\n", menor, meio, maior);
    return 0;
}
