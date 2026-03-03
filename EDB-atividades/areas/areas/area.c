// area.c
#include <math.h>
#include "area.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Implementação da função para calcular a área de um retângulo
double area_retangulo(double largura, double altura) {
    return largura * altura;
}

// Implementação da função para calcular a área de um triângulo
double area_triangulo(double base, double altura) {
    return (base * altura) / 2.0;
}

// Implementação da função para calcular a área de um círculo
double area_circulo(double raio) {
    return M_PI * raio * raio;
}

