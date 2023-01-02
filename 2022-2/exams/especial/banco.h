#ifndef BANCO_H_
#define BANCO_H_

#define DELIMITADOR ';'

typedef struct Conta {
    double saldo;
    double limite;
} Conta;

typedef struct Ativo {
    char tipo; // 'A', 'T', 'F'
    double valor;
} Ativo;

typedef struct Cliente {
    char *nome;
    Ativo ativos[3];
    Conta *conta;
} Cliente;

Cliente processa_cliente(char *linha);
int processa_arquivo(char *nome_arquivo, Cliente **clientes);
// Assume que `r` já foi alocado com tamanho `n`
// (mesmo tamanho que `clientes`).
int seleciona(Cliente *clientes, int n, int k, int i, Cliente *r);

#endif // BANCO_H_
