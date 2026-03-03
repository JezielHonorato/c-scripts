#include <stdio.h>
#include "cubo.h"

int main()
{
	double dimensao;
	Cubo cubo;

	printf("Digite o comprimento do cubo: ");
	scanf("%lf", &dimensao);
	cubo = criaCubo(dimensao);
	printf("Você tem um cubo de comprimento: %.2lf\n", comprimento(cubo));
	printf("o perimetro do seu cubo é: %.2lf\n", perimetro(cubo));
	printf("a area de uma das faces é: %.2lf\n", areaParcial(cubo));
	printf("todas as áreas somam : %.2lf\n", areaTotal(cubo));
	printf("o volume do seu cubo é: %.2lf\n", volume(cubo));

	return 0;
}
