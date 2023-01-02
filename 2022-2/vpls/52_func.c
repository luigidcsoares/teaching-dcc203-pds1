#include "52_func.h"

bool eh_triangulo(int a, int b, int c) {
    return a < (b + c) && b < (a + c) && c < (b + a);
}

unsigned char tipo_triangulo(int a, int b, int c) {
    if (a == b && b == c) {
        return 2; // Equilátero
    } else if (a == b || a == c || b == c) {
        return 1; // Isósceles
    } else {
        return 0; // Escaleno
    }
}
