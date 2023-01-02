#include "92_string.h"

#include <string.h>

void desloca_string(char *str, int i) {
    if (i >= strlen(str)) return;

    str[i] = str[i + 1];
    desloca_string(str, i + 1);
}

void apaga_caractere_aux(char *str, char c, int i) {
    if (i >= strlen(str)) return;

    if (str[i] == c) {
        desloca_string(str, i);
        apaga_caractere_aux(str, c, i);
    } else {
        apaga_caractere_aux(str, c, i + 1);
    }
}

void apaga_caractere(char *str, char c) {
    apaga_caractere_aux(str, c, 0);
}
