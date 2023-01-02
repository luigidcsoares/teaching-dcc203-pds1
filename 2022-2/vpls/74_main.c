#include <stdio.h>

#include "74_evento.h"

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    Evento agenda[100];
    cadastrar_eventos(agenda, n);

    Data d;
    scanf("%u", &d.dia);

    unsigned mes;
    scanf("%u", &mes);
    d.mes = mes;

    scanf("%u", &d.ano);

    imprimir_eventos(agenda, d, n);
    return 0;
}
