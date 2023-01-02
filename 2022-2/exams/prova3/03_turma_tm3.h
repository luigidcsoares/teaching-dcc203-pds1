#ifndef TURMA_H_
#define TURMA_H_

#include <stdbool.h>
#include <stdio.h>

#define DELIMITADOR '#'

typedef struct Aluno {
    char *matricula;
    char *nome;
    unsigned short nota;
} Aluno;

typedef struct Turma {
    Aluno *alunos;
    int n;
} Turma;

char *le_linha(FILE *file);
Aluno le_aluno(char *linha);
Turma *le_turma(char *nome_arquivo);
int indice_k(Turma t, unsigned int i, unsigned int k);

#endif
