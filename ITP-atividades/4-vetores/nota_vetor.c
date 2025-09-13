#include <stdio.h>

int estaOrdenado(int vetor[], int tamanho);

int main()
{
	int n;
	scanf("%d", &n);

	int vetor[10];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vetor[i]);
	}

	if (estaOrdenado(vetor, n))
	{
		printf("Vetor esta ordenado");
	}
	else
	{
		printf("Vetor nao esta ordenado");
	}

	return 0;
}

int estaOrdenado(int vetor[], int tamanho)
{
	for (int i = 0; i < tamanho - 1; i++)
	{
		if (vetor[i] > vetor[i + 1])
		{
			return 0;
		}
	}
	return 1;
}
