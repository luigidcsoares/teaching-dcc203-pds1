#include <stdio.h>

int main(int argc, char *argv[]) {
    char texto[100];
    fgets(texto, 100, stdin);

    int contador[] = {0, 0, 0, 0, 0};
    for (int i = 0; texto[i] != '\0'; i++) {
        switch (texto[i]) {
            case 'a':
            case 'A': contador[0]++; break;
            case 'e':
            case 'E': contador[1]++; break;
            case 'i':
            case 'I': contador[2]++; break;
            case 'o':
            case 'O': contador[3]++; break;
            case 'u':
            case 'U': contador[4]++; break;
        }
    }

    printf("A: %d, E: %d, I: %d, O: %d, U: %d\n",
           contador[0], contador[1], contador[2],
           contador[3], contador[4]);

    return 0;
}
