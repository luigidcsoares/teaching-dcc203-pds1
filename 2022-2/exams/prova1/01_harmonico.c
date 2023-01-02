#include <stdio.h>

int main(int argc, char *argv[]) {
    int n;
    scanf("%d", &n);

    float h = 0.0;
    for (int i = 1; i <= n; i++) {
        h += 1.0 / i;
    }

    printf("H(%d) = %f\n", n, h);
    return 0;
}
