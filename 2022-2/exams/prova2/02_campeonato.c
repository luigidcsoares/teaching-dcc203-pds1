#include "02_campeonato.h"
#include <stdio.h>

int vencedor(struct Partida p) {
    if (p.golsA > p.golsB) return p.timeA;
    return p.timeB;
}

void prox_fase(struct Fase *atual, struct Fase *prox) {
    prox->num_partidas = atual->num_partidas / 2;
    int i = 0;
    for (int j = 0; j < atual->num_partidas; j++) {
        int vencedor1 = vencedor(atual->partidas[i]);
        int vencedor2 = vencedor(atual->partidas[i + 1]);

        struct Partida p = {vencedor1, vencedor2, -1, -1};
        prox->partidas[j] = p;

        i += 2;
    }
}
