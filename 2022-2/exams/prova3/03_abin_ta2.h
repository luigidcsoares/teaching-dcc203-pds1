#ifndef ABIN_H_
#define ABIN_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct Funcionario {
    char *matricula;
    char *nome;
    unsigned short num_esp;
} Funcionario;

typedef struct Empregados {
    Funcionario *empregados;
    int n;
} Empregados;

char *le_linha(FILE *file);
Funcionario le_funcionario(char *linha);
Empregados *le_empregados(char *nome_arquivo);
void ordena_empregados(Empregados e);

// Os k primeiros estão ordenados em ordem decrescente?
// Assuma que k <= e.n
bool ordenado(Empregados e, int k);
bool ordenado_alt(Empregados e, int k);

#endif
