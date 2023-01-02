#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>

VetorAlunos filtrar_it(VetorAlunos v, Curso curso) {
  VetorAlunos r;

  r.capacidade = 10;
  r.n = 0;

  // Aloque espaco de acordo com a capacidade inicial:
  r.alunos = (Aluno *) malloc(r.capacidade * sizeof(Aluno));

  for (int i = 0; i < v.n; i++) {
    if (r.n >= r.capacidade) {
      // Dobre a capacidade:
      r.capacidade *= 2;
      // Realoque o espaco para comportar novos alunos:
      r.alunos = (Aluno *)realloc(r.alunos, r.capacidade * sizeof(Aluno));
    }

    if (v.alunos[i].curso->id == curso.id) {
      r.alunos[r.n] = v.alunos[i];
      r.n++;
    }
  }

  return r;
}

void filtrar_r_aux(VetorAlunos v, Curso curso, int i, VetorAlunos *r) {
  if (i >= v.n) return;

  if (r->n >= r->capacidade) {
    r->capacidade *= 2;
    r->alunos = (Aluno *) realloc(r->alunos, r->capacidade * sizeof(Aluno));
  }

  if (v.alunos[i].curso->id == curso.id) {
    r->alunos[r->n] = v.alunos[i];
    r->n++;
  }

  filtrar_r_aux(v, curso, i + 1, r);
}

VetorAlunos filtrar_r(VetorAlunos v, Curso curso) {
  VetorAlunos r;

  r.n = 0;
  r.capacidade = 10;
  r.alunos = (Aluno *) malloc(r.capacidade * sizeof(Aluno));

  filtrar_r_aux(v, curso, 0, &r);
  return r;
}

bool salvarAlunos(VetorAlunos v, char *nome_arquivo) {
  FILE *fp = fopen(nome_arquivo, "w");
  if (fp == NULL) return false;

  fprintf(fp, "Matrícula,Nome,Curso\n");
  for (int i = 0; i < v.n; i++) {
    fprintf(fp, "%s,%s,%d\n", v.alunos[i].matricula, v.alunos[i].nome,
            v.alunos[i].curso->id);
  }

  fclose(fp);
  return true;
}

VetorAlunos filtrar_r_alt(VetorAlunos v, Curso curso) {
  if (v.n == 0) {
    VetorAlunos r;

    r.n = 0;
    r.capacidade = 10;
    r.alunos = (Aluno *) malloc(r.capacidade * sizeof(Aluno));

    return r;
  }

  // Decrementa v.n para verificar subarranjo:
  v.n--;

  VetorAlunos r = filtrar_r_alt(v, curso);

  // v.n foi decrementado, portanto v.n agora
  // corresponde ao indice do ultimo aluno.
  if (v.alunos[v.n].curso->id != curso.id) {
    return r;
  }

  if (r.n >= r.capacidade) {
    r.capacidade *= 2;
    r.alunos = (Aluno *) realloc(r.alunos, r.capacidade * sizeof(Aluno));
  }

  r.alunos[r.n] = v.alunos[v.n];
  r.n++;

  return r;
}
