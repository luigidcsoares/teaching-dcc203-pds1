#include "74_evento.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void cadastrar_eventos(Evento *agenda, int n) {
    for (int i = 0; i < n; i++) {
        Evento e;

        scanf("%s %s", e.nome, e.local);
        scanf("%u", &e.data.dia);

        unsigned mes;
        scanf("%u", &mes);
        e.data.mes = mes;

        scanf("%u", &e.data.ano);
        agenda[i] = e;
    }
}

void imprimir_eventos(Evento *agenda, Data d, int n) {
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        Evento e = agenda[i];
        if (
            e.data.dia == d.dia &&
            e.data.mes == d.mes &&
            e.data.ano == d.ano
        ) {
            printf("%s %s\n", e.nome, e.local);
            encontrado = true;
        }
    }

    if (!encontrado) {
        printf("Nenhum evento encontrado!\n");
    }
}
