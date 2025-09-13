#include <stdio.h>

void imprimeSemRepeticao(int vetor[], int tamanho);

int main()
{
	int tamanho;
	scanf("%d", &tamanho);

	int vetor[100];
	for (int i = 0; i < tamanho; i++)
	{
		scanf("%d", &vetor[i]);
	}

	imprimeSemRepeticao(vetor, tamanho);

	return 0;
}

void imprimeSemRepeticao(int vetor[], int tamanho)
{
	for (int i = 0; i < tamanho; i++)
	{
		int repetido = 0;
		for (int j = 0; j < i; j++)
		{
			if (vetor[i] == vetor[j])
			{
				repetido = 1;
				break;
			}
		}
		if (!repetido)
		{
			printf("%d ", vetor[i]);
		}
	}
	printf("\n");
}
