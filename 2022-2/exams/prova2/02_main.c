#include <stdio.h>
#include "02_campeonato.h"

int main(int argc, char *argv[]) {
    int k;
    scanf("%d", &k);

    // Primeiro, vamos construir a fase inicial (k jogos):
    struct Fase inicial;
    inicial.num_partidas = k;

    int timeA = 0, timeB = 1;
    for (int i = 0; i < k; i++) {
        struct Partida p;

        p.timeA = timeA;
        p.timeB = timeB;

        scanf("%d %d", &p.golsA, &p.golsB);

        // Quais sao os identificadores dos dois proximos times?

        timeA += 2;

        timeB += 2;

        // Insira a partida na fase inicial:

        inicial.partidas[i] = p;
    }

    // Em seguida, vamos preencher as fases seguintes:
    // Quantos jogos tem a segunda fase?

    k = k / 2;
    struct Fase atual = inicial;
    while (k > 0) {
        struct Fase prox;
        // Utilize a função prox_fase que você criou para preencher "prox";

        prox_fase(&atual, &prox);
        for (int i = 0; i < prox.num_partidas; i++) {
            // Agora vamos ler os resultados dos jogos das próximas fases:
            scanf("%d %d", &prox.partidas[i].golsA, &prox.partidas[i].golsB);
        }

        // Quantos jogos tem a proxima fase?
        // Dica: o calculo eh o mesmo que para a segunda fase.

        k = k / 2;
        atual = prox;
    }

    //  "atual" sai do loop sendo a última fase (final). Imprima o campeão:
    printf("Campeão: %d\n", vencedor(atual.partidas[0]));

    return 0;
}
