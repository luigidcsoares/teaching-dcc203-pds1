#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "92_string.h"

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    char str[100];
    fgets(str, 100, stdin);

    char c = getchar();

    apaga_caractere(str, c);
    printf("%s", str);

    return 0;
}
