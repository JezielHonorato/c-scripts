#include <stdio.h>

int main()
{
	int carro, carro1, carro2, distanciaFrente, distanciaAtras, frente = -1, tras = -1;

	scanf("%d %d %d", &carro, &carro1, &carro2);

	if (carro1 > carro)
	{
		frente = carro1;
	}
	else
	{
		tras = carro1;
	}

	if (carro2 > carro)
	{
		frente = carro2;
	}
	else
	{
		tras = carro2;
	}

	if (frente == -1 || tras == -1)
	{
		printf("C");
	}
	else
	{
		distanciaFrente = frente - carro;
		distanciaAtras = tras - carro;
		if (distanciaFrente < 0)
		{
			distanciaFrente *= -1;
		}
		if (distanciaAtras < 0)
		{
			distanciaAtras *= -1;
		}

		if (distanciaAtras < distanciaFrente)
			printf("A");
		else if (distanciaFrente < distanciaAtras)
			printf("F");
		else
			printf("C");
	}

	return 0;
}
