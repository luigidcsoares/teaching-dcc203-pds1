#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ==============================================
// === Arquivos de texto vs arquivos binários ===
// ==============================================

/* int main(int argc, char **argv) { */
/*     FILE *p = fopen("arquivo.txt", "w"); */
/*     FILE *p2 = fopen("arquivo.bin", "wb"); */

/*     if (p == NULL) { */
/*         printf("Arquivo inválido!\n"); */
/*         return 1; */
/*     } */

/*     fputs("10 20 30 40 50", p); */

/*     // fwrite */
/*     char array[] = {10, 20, 30, 40, 50}; */
/*     fwrite(array, sizeof(char), 5, p2); */

/*     fclose(p); */
/*     fclose(p2); */

/*     p = fopen("arquivo.txt", "r"); */
/*     p2 = fopen("arquivo.bin", "rb"); */

/*     if (p == NULL) { */
/*         printf("Arquivo inválido!\n"); */
/*         return 1; */
/*     } */

/*     char array2[5]; */

/*     // Armazena em array2 o que foi lido: */
/*     fread(array2, sizeof(char), 5, p2); */

/*     for (int i = 0; i < 5; i++) { */
/*         printf("%d ", array2[i]); */
/*     } */

/*     fclose(p); */
/*     fclose(p2); */

/*     return 0; */
/* } */


// ==============================================
// ============ Bubblesort recursivo ============
// ==============================================

// [2, -1, 5, 8, 7] 8 vs 7  => ? || true  = true  || true  = true
// [2, -1, 5, 7, 8] 5 vs 7  => ? || false = true  || false = true
// [2, -1, 5, 7, 8] -1 vs 5 => ? || false = true  || false = true
// [2, -1, 5, 7, 8] 2 vs -1 => ? || true  = false || true  = true
// [-1, 2, 5, 7, 8] => false
//
// Exemplo 2:
// [8, -1, 5, 2, 7] 2 vs 7  => ? || false = true  || false = true
// [8, -1, 5, 2, 7] 5 vs 2  => ? || true  = true  || true  = true
// [8, -1, 2, 5, 7] -1 vs 2 => ? || false = true  || false = true
// [8, -1, 2, 5, 7] 8 vs -1 => ? || true  = false || true  = true
// [-1, 8, 2, 5, 7] => false

bool passo_bubblesort(int *A, int n) {
    if (n == 1) return false;

    bool troquei = false;
    if (A[n - 2] > A[n - 1]) {
        int tmp = A[n - 2];
        A[n - 2] = A[n - 1];
        A[n - 1] = tmp;

        troquei = true;
    }

    // a || b: quando a é verdadeiro, não olha o b
    // Logo, o return abaixo não funciona como gostaríamos:
    /* return troquei || passo_bubblesort(A, n - 1); */

    // Devemos fazer a recursão primeiro:
    return passo_bubblesort(A, n - 1) || troquei;

    // Ou usar o operador OR binário:
    /* return troquei | passo_bubblesort(A, n - 1); */
}

void bubblesort(int *A, int n) {
   bool troquei = passo_bubblesort(A, n);
   if (troquei) {
       bubblesort(A, n);
   }
}

/* int main(int argc, char **argv) { */
/*     /\* int A[5] = {8, -1, 5, 2, 7}; *\/ */

/*     FILE *file = fopen("vetor.txt", "r"); */

/*     if (file == NULL) { */
/*         printf("Arquivo inválido!\n"); */
/*         return 1; */
/*     } */

/*     int tamanho = 2; */
/*     int *A = (int *) malloc(tamanho * sizeof(int)); */

/*     int i = 0; */
/*     int num; */

/*     // Consome o primeiro valor, que já pode ser o final do arquivo. */
/*     fscanf(file, "%d", &num); */

/*     while (!feof(file)) { */
/*         if (i == tamanho) { */
/*             tamanho = tamanho + 1; */
/*             A = realloc(A, tamanho * sizeof(int)); */
/*         } */

/*         A[i] = num; */
/*         i++; */

/*         fscanf(file, "%d", &num); */
/*     } */

/*     bubblesort(A, 5); */

/*     for (int i = 0; i < tamanho; i++) { */
/*         printf("%d ", A[i]); */
/*     } */
/*     printf("\n"); */

/*     free(A); */
/*     fclose(file); */
/*     return 0; */
/* } */

// ==============================================
// ========= Copiar positivos recursivo =========
// ==============================================

// Copia elementos positivos de A para B.
// Assumimos que o tamanho reservado para B é o mesmo que para A.
int copiaPositivos(int *A, int *B, int i, int j, int n) {
    if (i >= n) {
        return 0;
    }

    if (A[i] > 0) {
        B[j] = A[i];
        return copiaPositivos(A, B, i + 1, j + 1, n) + 1;
    }

    return copiaPositivos(A, B, i + 1, j , n);
}

int main(int argc, char **argv) {
    int A[5] = {2, -1, 5, -3, 0};
    int B[5];

    int k = copiaPositivos(A, B, 0, 0, 5);
    printf("k: %d\n", k);

    for (int i = 0; i < k; i++) {
        printf("%d ", B[i]);
    }

    printf("\n");
    return 0;
}

// ==============================================
// ========== VPL 9.3 - Raíz recursiva ==========
// ==============================================

double absoluto(double a) {
    return a < 0 ? -a : a;
}

double raiz(double n, double palpite) {
    if (absoluto(palpite * palpite - n) <= 0.01) {
        return palpite;
    }

    if (palpite * palpite > n) {
        return raiz(n, palpite / 2);
    }

    return raiz(n, palpite * 1.5);
}

/* int main(int argc, char **argv) { */
/*     double n; */
/*     scanf("%lf", &n); */
/*     double r = raiz(n, n / 2); */
/*     printf("%0.2lf\n", r); */
/*     return 0; */
/* } */
