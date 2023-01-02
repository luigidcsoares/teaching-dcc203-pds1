#ifndef AGENDA_H_
#define AGENDA_H_

#include <stdbool.h>

// (1) Defina a estrutura Contato:
typedef struct Contato {
    char *nome;
    unsigned int idade;
    char celular[12];
} Contato;

// (2) Declare a função criar_contato:
Contato criar_contato(void);

// (3) Declare a função inserir_contato:
bool inserir_contato(Contato c, char *nome_arquivo);

// (4) Declare a função exibir_contatos:
bool exibir_contatos(char *nome_arquivo);

#endif // AGENDA_H_
