#include "03_abin_ta2.h"

#include <stdio.h>

int main(int argc, char **argv) {
    Empregados *e = le_empregados("03_abin_ta2.txt");
    if (e == NULL) {
        printf("ERRO: não foi possível abrir o arquivo!\n");
        return 1; // Retorno diferente de zero para indicar erro;
    }

    printf("Está ordenado?: %d\n", ordenado(*e, e->n));
    printf("Está ordenado?: %d\n", ordenado_alt(*e, e->n));

    ordena_empregados(*e);
    for (int i = 0; i < e->n; i++) {
        Funcionario f = e->empregados[i];
        printf("%s\t%s\t%u\n", f.matricula, f.nome, f.num_esp);
    }

    printf("Está ordenado?: %d\n", ordenado(*e, e->n));
    printf("Está ordenado?: %d\n", ordenado_alt(*e, e->n));
    return 0;
}
