// main.c
#include <stdio.h>
#include "area.h"

int main() {
    double largura, altura, base, raio;

    // Cálculo da área do retângulo
    printf("Digite a largura e altura do retângulo: ");
    scanf("%lf %lf", &largura, &altura);
    printf("Área do retângulo: %.2lf\n", area_retangulo(largura, altura));

    // Cálculo da área do triângulo
    printf("Digite a base e a altura do triângulo: ");
    scanf("%lf %lf", &base, &altura);
    printf("Área do triângulo: %.2lf\n", area_triangulo(base, altura));

    // Cálculo da área do círculo
    printf("Digite o raio do círculo: ");
    scanf("%lf", &raio);
    printf("Área do círculo: %.2lf\n", area_circulo(raio));

    return 0;
}

