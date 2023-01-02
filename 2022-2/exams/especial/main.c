#include "banco.h"

#include <stdlib.h>
#include <stdio.h>

int main(void) {
    Cliente *clientes = NULL;
    int n = processa_arquivo("banco.csv", &clientes);

    Cliente *filtrados = (Cliente *)malloc(n * sizeof(Cliente));
    int m = seleciona(clientes, n, 200.00, 0, filtrados);

    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
      printf("Nome: %s\n", filtrados[i].nome);
      printf("Saldo: %.2lf\n", filtrados[i].conta->saldo);
      printf("Limite: %.2lf\n", filtrados[i].conta->limite);
      printf("Ativo 1: %.2lf (%c)\n", filtrados[i].ativos[0].valor,
             filtrados[i].ativos[0].tipo);
      printf("Ativo 2: %.2lf (%c)\n", filtrados[i].ativos[1].valor,
             filtrados[i].ativos[1].tipo);
      printf("Ativo 3: %.2lf (%c)\n", filtrados[i].ativos[2].valor,
             filtrados[i].ativos[2].tipo);
      printf("=======================================\n");
    }
    return 0;
}
