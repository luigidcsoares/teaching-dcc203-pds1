#include "banco.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ResultadoProcValor {
    double valor;
    unsigned int tamanho;
} ResultadoProcValor;

ResultadoProcValor processa_valor(char *linha) {
    double inteiro = 0.0;
    // Assume que o separador de decimal é um "ponto".
    // 400.15:
    // inteiro = 0 * 10 + 4 = 4
    // inteiro = 4 * 10 + 0 = 40
    // inteiro = 40 * 10 + 0 = 400
    int i;
    for (i = 0; linha[i] != '.'; i++) {
        inteiro = inteiro * 10 + (linha[i] - '0');
    }
    double decimal = 0.0;
    double div = 10.0;
    // decimal = 0 + 1 / 10 = 0.1
    // decimal = 0.1 + 5/100 = 0.1 + 0.05 = 0.15
    for (i++; linha[i] != DELIMITADOR && linha[i] != '\0'; i++) {
        decimal += (linha[i] - '0') / div;
        div *= 10;
    }

    ResultadoProcValor r;
    r.valor = inteiro + decimal;
    r.tamanho = i;

    return r;
}

Cliente processa_cliente(char *linha) {
    Cliente c;

    // Nome do cliente:
    int i;
    c.nome = (char *)malloc(150 * sizeof(char));
    for (i = 0; linha[i] != DELIMITADOR; i++) {
        c.nome[i] = linha[i];
    }
    c.nome = (char *) realloc(c.nome, (strlen(c.nome) + 1) * sizeof(char));

    i++; // Pula delimitador

    // Conta do cliente:
    c.conta = (Conta *)malloc(sizeof(Conta));

    ResultadoProcValor r = processa_valor(&linha[i]);
    c.conta->saldo = r.valor;

    i += r.tamanho; // Move para o delimitador
    i++; // Pula o delimitador

    r = processa_valor(&linha[i]);
    c.conta->limite = r.valor;

    i += r.tamanho; // Move para o delimitador

    // Ativos do cliente:
    for (int j = 0; linha[i] != '\0'; j++) {
        i++; // Pula o delimitador
        c.ativos[j].tipo = linha[i];

        i++;
        r = processa_valor(&linha[i]);
        c.ativos[j].valor = r.valor;

        i += r.tamanho; // Move para o delimitador ou final da linha
    }

    return c;
}

#define TAMANHO_MAX_LINHA 150
int processa_arquivo(char *nome_arquivo, Cliente **clientes) {
    FILE *fp = fopen(nome_arquivo, "r");

    if (fp == NULL) {
        return -1;
    }

    int n = 0;
    int capacidade = 10;

    // Aloque espaco para 10 clientes (utilize a variavel capacidade):
    *clientes = (Cliente *)malloc(capacidade * sizeof(Cliente));

    char linha[TAMANHO_MAX_LINHA + 1];

    // A primeira linha do arquivo eh o cabeçalho com o nome de
    // cada coluna. Ela não sera utilizada, mas preciamos passar
    // por ela. Pule a primeira linha:
    fgets(linha, TAMANHO_MAX_LINHA + 1, fp);

    // Agora leia a segunda linha, que potencialmente eh um cliente:
    fgets(linha, TAMANHO_MAX_LINHA + 1, fp);

    // Como saber se chegamos ao final do arquivo? Indique a condicao:
    while (!feof(fp)) {
        if (linha[strlen(linha) - 1] == '\n') {
            linha[strlen(linha) - 1] = '\0';
        }

        // Utilize a funcao processa_cliente para processar a linha lida:
        Cliente c = processa_cliente(linha);

        if (n >= capacidade) {
            capacidade *= 2;
            // Realoque o vetor de clientes de acordo com a nova capacidade:
            *clientes =
                (Cliente *)realloc(*clientes, capacidade * sizeof(Cliente));
        }

        (*clientes)[n] = c;
        n++;

        // Leia a proxima linha:
        fgets(linha, TAMANHO_MAX_LINHA + 1, fp);
    }

    fclose(fp);
    return n;
}

int seleciona(Cliente *clientes, int n, int k, int i, Cliente *r) {
    if (n == 0) {
        return 0;
    }

    if (clientes[n - 1].conta->saldo >= k) {
      r[i] = clientes[n - 1];
      return 1 + seleciona(clientes, n - 1, k, i + 1, r);
    }

    return seleciona(clientes, n - 1, k, i, r);
}
