#ifndef EVENTO_H_
#define EVENTO_H_

typedef enum Mes {
    JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ
} Mes;

typedef struct Data {
    unsigned dia;
    enum Mes mes;
    unsigned ano;
} Data;

typedef struct Evento {
    char nome[101]; // 100 caracteres + 1 \0
    char local[101]; // 100 caracteres + 1 \0
    Data data;
} Evento;

void cadastrar_eventos(Evento *agenda, int n);
void imprimir_eventos(Evento *agenda, Data d, int n);

#endif
