#ifndef ALUNO_H_
#define ALUNO_H_

#include <stdbool.h>
#include "curso.h"

typedef struct Aluno {
  char matricula[7]; // 6 digitos + \0
  char *nome;
  Curso *curso;
} Aluno;

typedef struct VetorAlunos {
  Aluno *alunos;
  unsigned int capacidade; // sempre >= n
  unsigned int n;
} VetorAlunos;

VetorAlunos filtrar_it(VetorAlunos v, Curso curso);
VetorAlunos filtrar_r(VetorAlunos v, Curso curso);

// Versão alternativa, sem funções auxiliares.
VetorAlunos filtrar_r_alt(VetorAlunos v, Curso curso);

bool salvarAlunos(VetorAlunos v, char *nome_arquivo);
#endif // ALUNO_H_
