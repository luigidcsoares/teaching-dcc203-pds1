#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "02_auth.h"

// ===============================================
// =========== NÃO ALTERE ESTE ARQUIVO ===========
// ===============================================

int main(int argc, char *argv[]) {
    BancoDados bd;
    scanf("%d\n", &bd.n);

    bd.usuarios = (Usuario *) malloc(bd.n * sizeof(Usuario));

    for (int i = 0; i < bd.n; i++) {
        char linha[100];
        fgets(linha, 100, stdin);

        // strcspn é uma função da biblioteca string.h.
        // strcspn(linha, " ") vai retornar o tamanho do
        // segmento inicial de "linha" que não contém um espaço.
        // Ou seja, considerando que a entrada é
        //     usuario senha
        // o retorno da função strcspn seria o tamanho de "usuario".
        // Precisamos deste tamanho para alocar o arranjo com malloc.
        int tam_usuario = strcspn(linha, " ") + 1; // +1 para o \0
        int tam_senha = strlen(linha) - tam_usuario;

        Usuario u;
        u.usuario = (char *) malloc(tam_usuario * sizeof(char));
        u.senha = (char *) malloc(tam_senha * sizeof(char));

        sscanf(linha, "%s %s", u.usuario, u.senha);

        u.senha = vignere(u.senha, u.usuario);
        bd.usuarios[i] = u;

        printf("%s\n", u.senha);
    }

    int m;
    scanf("%d\n", &m);
    for (int i = 0; i < m; i++) {
        char linha[100];
        fgets(linha, 100, stdin);

        int tam_usuario = strcspn(linha, " ") + 1; // +1 para o \0
        int tam_senha = strlen(linha) - tam_usuario;

        Usuario u;
        u.usuario = (char *) malloc(tam_usuario * sizeof(char));
        u.senha = (char *) malloc(tam_senha * sizeof(char));

        sscanf(linha, "%s %s", u.usuario, u.senha);

        if (autenticar(u, bd)) {
            printf("Autenticação feita com sucesso!\n");
        } else {
            printf("Falha na autenticação!\n");
        }
    }

    return 0;
}
