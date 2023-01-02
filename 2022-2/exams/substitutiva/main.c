#include "stdio.h"
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

void remove_newline(char *str) {
  if (str[strlen(str) - 1] == '\n') {
    str[strlen(str) - 1] = '\0';
  }

  str = (char *) realloc(str, strlen(str) * sizeof(char));
}

#define BUFFER_SIZE 150
int main(void) {
    VetorAlunos v;

    v.capacidade = 10;
    v.alunos = (Aluno *) malloc(v.capacidade * sizeof(Aluno));

    /* printf("#Alunos: "); */
    scanf("%d", &v.n);
    getchar();

    for (int i = 0; i < v.n; i++) {
      if (i >= v.capacidade) {
        v.capacidade *= 2;
        // Realoque o espaco para comportar novos alunos:
        v.alunos = (Aluno *)realloc(v.alunos, v.capacidade);
      }

      Aluno a;

      a.nome = (char *) malloc(BUFFER_SIZE * sizeof(char));
      a.curso = (Curso *) malloc(sizeof(Curso));
      a.curso->nome = (char *) malloc(BUFFER_SIZE * sizeof(char));

      /* printf("Matrícula: "); */
      fgets(a.matricula, 7, stdin);
      getchar();

      /* printf("Nome: "); */
      fgets(a.nome, BUFFER_SIZE, stdin);

      /* printf("ID do curso: "); */
      scanf("%d", &a.curso->id);
      getchar();

      /* printf("Nome do curso: "); */
      fgets(a.curso->nome, BUFFER_SIZE, stdin);

      /* printf("Departamento: "); */
      fgets(a.curso->departamento, 4, stdin);
      getchar();

      remove_newline(a.nome);
      remove_newline(a.curso->nome);

      v.alunos[i] = a;
    }

    Curso c = {1, "Ciência da Computação", "DCC"};

    VetorAlunos it = filtrar_it(v, c);
    VetorAlunos r = filtrar_r(v, c);
    VetorAlunos r_alt = filtrar_r_alt(v, c);

    printf("%d %d %d %d\n", v.n, it.n, r.n, r_alt.n);
    salvarAlunos(it, "alunos_it.csv");
    salvarAlunos(r, "alunos_r.csv");
    salvarAlunos(r_alt, "alunos_r_alt.csv");
}
