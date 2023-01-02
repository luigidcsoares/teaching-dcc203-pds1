#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdbool.h>

/**
 * Esta função troca os valores A[i] e A[j]. Seja A' o arranjo final
 * (atualizado), temos que A'[i] = A[j] e A'[j] = A[i].  Note que A' é apenas
 * uma forma de indicar o estado final do arranjo A; a troca será feita no
 * próprio arranjo A passado por parâmetro.
 *
 * Arranjos são passados para funções como ponteiros ("A" corresponde, ou aponta,
 * para a primeira posição do espaço reservado para o arranjo). Veremos ponteiros
 * mais adiante no curso. Neste momento, basta que você visualize o parâmetro "A"
 * como um arranjo, e.g. acessando um elemento na posição i como A[i].
 *
 * Esta função assume que i e j não ultrapassam o tamanho do arranjo A.
 *
 * @param A Arranjo que terá os valores trocados de posição
 * @param i Posição do arranjo
 * @param j Posição do arranjo
 */
void swap(int *A, unsigned i, unsigned j);

/**
 * Esta função verifica se o arranjo A está ordenado (em ordem crescente).
 *
 * @param A Arranjo a ser verificado
 * @param n Tamanho do arranjo
 *
 * @return true se o arranjo está ordenado ou false caso contrário.
 */
bool sorted(int *A, int n);

/**
 * Esta função implementa o algoritmo Bubble Sort. Ao final, o arranjo
 * A deve estar ordenado em ordem crescente.
 *
 * @param A Arranjo a ser ordenado
 * @param n Tamanho do arranjo
 */
void bubblesort(int *A, int n);

#endif
