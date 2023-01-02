#include "02_auth.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#define TAM_ALFABETO 26
char *vignere(char *texto, char *chave) {
    int n = strlen(texto);
    char *cifrado = (char *) malloc((n + 1) * sizeof(char));

    int idx_chave = 0;
    for (int i = 0; i < n; i++) {
        int cod_texto = texto[i] - 'a';
        int deslocamento = chave[idx_chave] - 'a';

        int cod_cifrado = cod_texto + deslocamento;
        if (cod_cifrado >= TAM_ALFABETO) {
            // Também seria possível fazer com o operador de resto %
            cod_cifrado -= TAM_ALFABETO;
        }

        cifrado[i] = cod_cifrado + 'a';
        idx_chave = (idx_chave + 1) % strlen(chave);
    }

    cifrado[n] = '\0';
    return cifrado;
}

char *des_vignere(char *cifrado, char *chave) {
    int n = strlen(cifrado);
    char *texto = (char *) malloc((n + 1) * sizeof(char));

    int idx_chave = 0;
    for (int i = 0; i < n; i++) {
        int cod_cifrado = cifrado[i] - 'a';
        int deslocamento = chave[idx_chave] - 'a';

        int cod_texto = cod_cifrado - deslocamento;
        if (cod_texto < 0) {
            cod_texto += TAM_ALFABETO;
        }

        texto[i] =  cod_texto + 'a';
        idx_chave = (idx_chave + 1) % strlen(chave);
    }

    texto[n] = '\0';
    return texto;
}

bool autenticar(Usuario u, BancoDados bd) {
    for (int i = 0; i < bd.n; i++) {
        char *usuario_i = bd.usuarios[i].usuario;
        if (strcmp(u.usuario, usuario_i) == 0) {
            char *senha_i = bd.usuarios[i].senha;
            return strcmp(u.senha, des_vignere(senha_i, usuario_i)) == 0;
        }
    }

    return false;
}
