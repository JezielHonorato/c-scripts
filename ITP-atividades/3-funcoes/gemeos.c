#include <stdio.h>

int ehPrimo(int numero), primoGemeo(int numero);

int main()
{
	int numero;
	scanf("%d", &numero);
	if (primoGemeo(numero))
		printf("Numero forma par de gemeos");
	else
		printf("Numero nao forma par de gemeos");
	return 0;
}

int ehPrimo(int numero)
{
	if (numero < 2)
	{
		return 0;
	}
	for (int i = 2; i * i <= numero; i++)
	{
		if (numero % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int primoGemeo(int numero)
{
	if (ehPrimo(numero) && ehPrimo(numero + 2))
	{
		return 1;
	}
	return 0;
}