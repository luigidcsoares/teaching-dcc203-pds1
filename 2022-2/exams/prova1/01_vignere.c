#include <stdio.h>

int main(int argc, char *argv[]) {
    char chave0, chave1, chave2, chave3;
    scanf(" %c %c %c %c", &chave0, &chave1, &chave2, &chave3);

    // Queremos o "valor" do caractere no nosso alfabeto
    // (entre 0 e 26).
    chave0 = chave0 - 'A';
    chave1 = chave1 - 'A';
    chave2 = chave2 - 'A';
    chave3 = chave3 - 'A';

    char c;
    scanf(" %c", &c);

    unsigned contador_chave = 0;

    // Caractere '#' indica final da entrada
    while (c != '#') {
        switch (contador_chave) {
        case 0:
            printf("%c", c + chave0);
            break;
        case 1:
            printf("%c", c + chave1);
            break;
        case 2:
            printf("%c", c + chave2);
            break;
        case 3:
            printf("%c", c + chave3);
            break;
        }

        contador_chave = (contador_chave + 1) % 4;
        scanf(" %c", &c);
    }

    printf("\n");
    return 0;
}
