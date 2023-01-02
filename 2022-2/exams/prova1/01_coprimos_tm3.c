#include <stdio.h>

int main(int argc, char *argv[]) {
    int x, y;
    scanf("%d%d", &x, &y);

    // mdc(x, y) <= x e mdc(x, y) <= y
    int mdc = x < y ? x : y;
    while (x % mdc != 0 || y % mdc != 0) {
        mdc--;
    }

    if (mdc == 1) {
        printf("%d e %d são primos entre si!\n", x, y);
    } else {
        printf("%d e %d não são primos entre si!\n", x, y);
    }

    return 0;
}
