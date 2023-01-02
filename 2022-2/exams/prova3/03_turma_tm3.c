#include "03_turma_tm3.h"

#include <stdlib.h>
#include <string.h>

#define MAX_TAMANHO_LINHA 150
char *le_linha(FILE *file) {
    char *linha = (char *) malloc((MAX_TAMANHO_LINHA + 1) * sizeof(char));

    // Se, por algum motivo acontecer um erro, não retorna nenhum
    // funcionário.
    if (fgets(linha, MAX_TAMANHO_LINHA + 1, file) == NULL) {
        return NULL;
    }

    // Vamos tirar a quebra de linha, caso exista:
    if (linha[strlen(linha) - 1] == '\n') {
        linha[strlen(linha) - 1] = '\0';
    }

    return linha;
}

Aluno le_aluno(char *linha) {
    Aluno a;

    // Aloque, inicialmente, espaco para 5 caracteres no nome e matricula:
    int n = 5;
    a.matricula = (char *) malloc(n * sizeof(char));
    a.nome = (char *) malloc(n * sizeof(char));

    a.matricula[0] = '\0';
    a.nome[0] = '\0';

    int i;
    for (i = 0; linha[i] != DELIMITADOR; i++) {
        // Aumente o espaco reservado em 5 posicoes (dica: `n` nao muda)
        a.matricula = (char *) realloc(a.matricula, n * (i + 2) * sizeof(char));
        a.matricula[i] = linha[i];
        a.matricula[i + 1] = '\0';
    }

    // `i` sai do loop anterior como sendo o indice do delimitador.
    int j = 0;
    for (i = i + 1; linha[i] != DELIMITADOR; i++, j++) {
        // Aumente o espaco reservado em 5 posicoes (dica: `n` nao muda)
        a.nome = (char *) realloc(a.nome, n * (i + 2) * n * sizeof(char));
        a.nome[j] = linha[i];
        a.nome[j + 1] = '\0';
    }

    int mult = 1;
    a.nota = 0;

    // `i` sai do loop anterior como sendo o indice do delimitador.
    for (int j = strlen(linha) - 1; j > i; j--) {
        a.nota += (linha[j] - '0') * mult;
        mult *= 10;
    }

    return a;
}

Turma *le_turma(char *nome_arquivo) {
    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL) return NULL;

    // Aloque espaco para UM valor do tipo Turma.
    Turma *t = (Turma *) malloc(sizeof(Turma));
    t->alunos = NULL; // Inicialmente nao temos nenhum aluno.
    t->n = 0;

    char *linha = le_linha(file); // Leia uma linha com a funcao le_linha.
    while (linha != NULL) {
        Aluno a = le_aluno(linha); // Leia um aluno.
        // Abra espaco no arranjo `alunos` para um novo aluno:
        t->n = t->n + 1;
        int bytes = t->n * sizeof(Aluno);
        t->alunos = (Aluno *) realloc(t->alunos, bytes);
        t->alunos[t->n - 1] = a; // Insira o aluno no arranjo.
        linha = le_linha(file); // Leia a proxima linha;
    }

    fclose(file);
    return t;
}

int indice_k(Turma t, unsigned int i, unsigned int k) {
    if (i >= t.n) {
        return -1;
    }

    if (t.alunos[i].nota < k) {
        return indice_k(t, i + 1, k);
    }

    return i;
}
