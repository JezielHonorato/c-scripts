#include <stdio.h>

int maior(int vet[], int tam);

int main()
{
	int tamanhoVetor;
	scanf("%d", &tamanhoVetor);
	int vetor[tamanhoVetor];
	for (int i = 0; i < tamanhoVetor; i++)
	{
		scanf("%d", &vetor[i]);
	}
	int resultado = maior(vetor, tamanhoVetor);
	printf("O maior é: %d\n", resultado);
	return 0;
}

int maior(int vet[], int tam)
{
	int maiorValor = vet[0];
	for (int i = 1; i < tam; i++)
	{
		if (vet[i] > maiorValor)
		{
			maiorValor = vet[i];
		}
	}
	return maiorValor;
}
