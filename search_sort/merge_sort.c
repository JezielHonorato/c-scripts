#include <stdio.h>

void exibeVetor(int vetor[], int n);
void mergeSort(int vetor[], int inicio, int fim);
void merge(int vetor[], int inicio, int meio, int fim);

int main()
{
	int vetor[] = {12, 9, 10, 13, 11, 14}, n = 6;

	printf("vetor de entrada: \n");
	exibeVetor(vetor, n);

	mergeSort(vetor, 0, n - 1);

	printf("vetor ordenado: \n");
	exibeVetor(vetor, n);

	return 0;
}

void exibeVetor(int vetor[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", vetor[i]);
	printf("\n");
}

void mergeSort(int vetor[], int inicio, int fim)
{
	if (inicio < fim) // quando a variavel fim for maior a funcao ser interrompida
	{
		int meio = inicio + (fim - inicio) / 2;

		mergeSort(vetor, inicio, meio);	 // de maneira recursiva a função vai dividir o vetor ate encontrar so um elemento
		mergeSort(vetor, meio + 1, fim); // funciona como a linha acima porem pega a segunda metade

		merge(vetor, inicio, meio, fim); // apos dividir
	}
}

void merge(int vetor[], int inicio, int meio, int fim)
{
	int i, j, k; // variaveis do for
	int n1 = meio - inicio + 1;
	int n2 = fim - meio;

	int v1[n1], v2[n2];

	for (i = 0; i < n1; i++)
		v1[i] = vetor[inicio + i]; // cria uma copia do intervalo do vetor original
	for (j = 0; j < n2; j++)
		v2[j] = vetor[meio + 1 + j]; // copia do outro intervalor

	i = 0;
	j = 0;
	k = inicio;
	while (i < n1 && j < n2)
	{
		if (v1[i] <= v2[j])
		{
			vetor[k] = v1[i]; // altera o vetor original para qe o elemento a esquerda seja o menor
			i++;
		}
		else
		{
			vetor[k] = v2[j];
			j++;
		}
		k++;
	}

	while (i < n1) // se existirem mais elementos a direita
	{
		vetor[k] = v1[i];
		i++;
		k++;
	}

	while (j < n2) // se existirem mais elementos a esquerda
	{
		vetor[k] = v2[j];
		j++;
		k++;
	}
}