#include "03_turma_tm3.h"

#include <stdio.h>

int main(int argc, char **argv) {
    FILE *file = fopen("03_turma_tm3.txt", "r");
    Turma *t = le_turma("03_turma_tm3.txt");
    if (t == NULL) {
        printf("ERRO: não foi possível abrir o arquivo!\n");
        return 1; // Retorno diferente de zero para indicar erro;
    }

    for (int i = 0; i < t->n; i++) {
        Aluno a = t->alunos[i];
        printf("%s\t%s\t\t%u\n", a.matricula, a.nome, a.nota);
    }

    int k;
    printf("\nNota: ");

    scanf("%d", &k);
    printf("Indice >= %d: %d\n", k, indice_k(*t, 0, k));

    return 0;
}
