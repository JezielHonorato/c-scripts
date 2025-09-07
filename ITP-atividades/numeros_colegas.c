#include <stdio.h>
#include <stdlib.h>

int soma_divisores(int numero), sao_colegas(int numero1, int numero2);

int main()
{
	int numero1, numero2;

	scanf("%d %d", &numero1, &numero2);
	if (sao_colegas(numero1, numero2))
	{
		printf("S");
	}
	else
	{
		printf("N");
	}

	return 0;
}

int soma_divisores(int numero)
{
	int soma = 0;
	for (int i = 1; i <= numero / 2; i++)
	{
		if (numero % i == 0)
		{
			soma += i;
		}
	}
	return soma;
}

int sao_colegas(int numero1, int numero2)
{
	int soma1 = soma_divisores(numero1);
	int soma2 = soma_divisores(numero2);
	return ((abs(soma1 - numero2) <= 2) && (abs(soma2 - numero1) <= 2));
}
