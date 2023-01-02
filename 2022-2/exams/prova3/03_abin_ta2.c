#include "03_abin_ta2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TAMANHO_LINHA 150

char *le_linha(FILE *file) {
    char *linha = (char *) malloc((MAX_TAMANHO_LINHA + 1) * sizeof(char));

    // Se, por algum motivo acontecer um erro,
    // não retorna nenhum funcionário
    if (fgets(linha, MAX_TAMANHO_LINHA + 1, file) == NULL) {
        return NULL;
    }

    // Vamos tirar a quebra de linha, caso exista:
    if (linha[strlen(linha) - 1] == '\n') {
        linha[strlen(linha) - 1] = '\0';
    }

    return linha;
}

#define DELIMITADOR ';'
Funcionario le_funcionario(char *linha) {
    Funcionario f;

    // Aloque, inicialmente, espaco para 1 caractere no nome e matricula:
    f.matricula = (char *) malloc(sizeof(char));
    f.nome = (char *) malloc(sizeof(char));

    f.matricula[0] = '\0';
    f.nome[0] = '\0';

    int i;
    for (i = 0; linha[i] != DELIMITADOR; i++) {
        // Aumente o espaco da matricula para caber mais um caractere:
        f.matricula = (char *) realloc(f.matricula, (i + 2) * sizeof(char));
        f.matricula[i] = linha[i];
        f.matricula[i + 1] = '\0';
    }

    // `i` sai do loop anterior como sendo o indice do delimitador.
    int j = 0;
    for (i = i + 1; linha[i] != DELIMITADOR; i++, j++) {
        // Aumente o espaco do nome para caber mais um caractere:
        f.nome = (char *) realloc(f.nome, (j + 2) * sizeof(char));
        f.nome[j] = linha[i];
        f.nome[j + 1] = '\0';
    }

    int mult = 1;
    f.num_esp = 0;

    // `i` sai do loop anterior como sendo o indice do delimitador.
    for (int j = strlen(linha) - 1; j > i; j--) {
        f.num_esp += (linha[j] - '0') * mult;
        mult *= 10;
    }

    return f;
}

Empregados *le_empregados(char *nome_arquivo) {
    FILE *file = fopen(nome_arquivo, "r");
    if (file == NULL) return NULL;

    // Aloque espaco para > um < valor do tipo Empregados.
    Empregados *e = (Empregados *) malloc(sizeof(Empregados));
    e->empregados = NULL; // Inicialmente nao temos nenhum empregado.
    e->n = 0;

    char *linha = le_linha(file); // Leia uma linha com a funcao le_linha.
    while (linha != NULL) {
        Funcionario f = le_funcionario(linha); // Leia um funcionario.
        // Abra espaco no arranjo `empregados` para um novo funcionario:
        e->n = e-> n + 1;
        int bytes = e->n * sizeof(Funcionario);
        e->empregados = (Funcionario *) realloc(e->empregados, bytes);
        e->empregados[e->n - 1] = f; // Insira o funcionario no arranjo.
        linha = le_linha(file); // Leia a proxima linha;
    }

    fclose(file);
    return e;
}

void swap(Funcionario *f, int i, int j) {
    Funcionario tmp = f[i];
    f[i] = f[j];
    f[j] = tmp;
}

bool bubblesort_step(Funcionario *f, int n) {
    if (n <= 1) {
        return 0;
    }

    bool swapped = false;
    if (f[n - 1].num_esp > f[n - 2].num_esp) {
        swap(f, n - 1, n - 2);
        swapped = true;
    }

    return swapped || bubblesort_step(f, n - 1);
}

void bubblesort(Funcionario *f, int n) {
    bool swapped = bubblesort_step(f, n);
    if (swapped) bubblesort(f, n);
}

void ordena_empregados(Empregados e) {
    bubblesort(e.empregados, e.n);
}

bool ordenado(Empregados e, int k) {
    if (k <= 1) {
        return true;
    }

    if (e.empregados[k - 2].num_esp < e.empregados[k - 1].num_esp) {
        return false;
    }

    return ordenado(e, k - 1);
}

bool ordenado_alt(Empregados e, int k) {
    if (k > 1 && e.empregados[k - 1].num_esp <= e.empregados[k - 2].num_esp) {
        return ordenado(e, k - 1);
    }

    /* if (k > 1  && e.empregados[k - 1].num_esp > e.empregados[k - 2].num_esp) { */
    if (k > 1) {
       return false;
    }

    return true;
}
