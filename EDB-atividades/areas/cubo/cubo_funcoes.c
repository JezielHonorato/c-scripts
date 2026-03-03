#include "cubo.h"

Cubo criaCubo(double comprimento)
{
	Cubo cubo;

	cubo.comprimento = comprimento;

	return cubo;
}

double perimetro(Cubo cubo)
{
	return (12 * cubo.comprimento);
}

double comprimento(Cubo cubo)
{
	return cubo.comprimento;
}

double areaParcial(Cubo cubo)
{
	return (cubo.comprimento * cubo.comprimento);
}

double areaTotal(Cubo cubo)
{
	return (cubo.comprimento * cubo.comprimento * 6);
}

double volume(Cubo cubo)
{
	return (cubo.comprimento * cubo.comprimento * cubo.comprimento);
}
