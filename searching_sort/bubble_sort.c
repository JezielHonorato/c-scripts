#include <stdio.h>

void bubbleSort(int vetor[], int n)
{
	for (int i = 0; i < (n - 1); i++)
	{
		for (int j = 0; j < (n - i - 1); j++)
		{
			if (vetor[j] > vetor[j + 1])
			{
				int temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
		}
	}
}