#include <stdio.h>

void selectionSort(int vetor[], int n)
{
	int indice, temp;
	for (int i = 0; i < (n - 1); i++)
	{
		indice = i;
		for (int j = (i + 1); j < n; j++)
		{
			if (vetor[j] < vetor[indice])
			{
				indice = j;
				temp = vetor[indice];
				vetor[indice] = vetor[i];
				vetor[i] = temp;
			}
		}
	}
}