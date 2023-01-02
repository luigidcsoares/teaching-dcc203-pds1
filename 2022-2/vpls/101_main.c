#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "101_agenda.h"

int main(int argc, char *argv[]) {
    char nome_arquivo[100];
    scanf("%s", nome_arquivo);

    int k;
    scanf("%d\n", &k);

    for (int i = 0; i < k; i++) {
        Contato c = criar_contato();
        inserir_contato(c, nome_arquivo);
    }

    exibir_contatos(nome_arquivo);
    return 0;
}
