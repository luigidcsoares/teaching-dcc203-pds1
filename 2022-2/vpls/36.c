#include <stdio.h>

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    int num;
    scanf("%d", &num);

    int menor = num;
    int maior = num;

    for (int i = 1; i < n; i++) {
        scanf("%d", &num);
        if (num > maior) maior = num;
        else if (num < menor) menor = num;
    }

    printf("Menor: %d\n", menor);
    printf("Maior: %d\n", maior);

    return 0;
}
