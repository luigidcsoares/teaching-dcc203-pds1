#include <stdio.h>

int main(int argc, char *argv[]) {
    int vel_max, vel_reg;
    scanf("%d %d", &vel_max, &vel_reg);

    if (vel_max <= 0 || vel_reg <= 0)
        printf("Velocidades Inválidas");
    else if (vel_reg <= vel_max)
        printf("Sem Infração");
    else if (vel_reg <= vel_max * 1.2)
        printf("Infração Média");
    else if (vel_reg <= vel_max * 1.5)
        printf("Infração Grave");
    else
        printf("Infração Gravíssima");

    return 0;
}
