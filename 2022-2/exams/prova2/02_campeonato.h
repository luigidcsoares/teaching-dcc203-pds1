#ifndef CAMPEONATO_H_
#define CAMPEONATO_H_

struct Partida {
    int timeA, timeB;
    int golsA, golsB;
};

struct Fase {
    struct Partida partidas[64];
    int num_partidas;
};

int vencedor(struct Partida p);
void prox_fase(struct Fase *atual, struct Fase *prox);

#endif
