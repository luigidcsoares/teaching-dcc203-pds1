#include <stdio.h>

int main(int argc, char *argv[]) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    // mmc(a, b, c) >= a, mmc(a, b, c) >= b e mmc(a, b, c) >= c
    int mmc = a;
    if (mmc < b) mmc = b;
    if (mmc < c) mmc = c;

    // O mmc deve ser divisível por a, b e c. Enquanto não for,
    // não encontramos o mmc.
    while (mmc % a != 0 || mmc % b != 0 || mmc % c != 0) {
        mmc++;
    }

    printf("mmc(%d, %d, %d) = %d\n", a, b, c, mmc);
    return 0;
}
