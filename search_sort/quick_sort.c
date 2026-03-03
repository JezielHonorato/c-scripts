// Quicksort

#include <stdio.h>

void troca(int *a, int *b);
int particiona(int v[], int inicio, int fim);
void quick_sort(int v[], int inicio, int fim);
void exibe_vetor(int v[], int n);

int main()
{
	int v[] = {12, 9, 10, 13, 11, 14}, n = 6;

	printf("vetor de entrada: \n");
	exibe_vetor(v, n);

	quick_sort(v, 0, n - 1);

	printf("vetor ordenado: \n");
	exibe_vetor(v, n);

	return 0;
}

void exibe_vetor(int v[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void quick_sort(int v[], int inicio, int fim)
{
	if (inicio < fim)
	{
		int indice_pivo = particiona(v, inicio, fim);

		quick_sort(v, inicio, indice_pivo - 1);
		quick_sort(v, indice_pivo + 1, fim);
	}
}

int particiona(int v[], int inicio, int fim)
{
	int pivo = v[fim]; // o pivo sera o elemento que esta na ultima posicao
	int i = (inicio - 1);

	for (int j = inicio; j <= fim - 1; j++)
	{
		if (v[j] <= pivo) // se o elemento for menor ou igual ele vai para a esquerda o pivo
		{
			i++;
			troca(&v[i], &v[j]);
		}
	}

	troca(&v[i + 1], &v[fim]); // coloca o pivo na posicao correta

	return (i + 1);
}

void troca(int *a, int *b) // trocar valores das variaveis
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
