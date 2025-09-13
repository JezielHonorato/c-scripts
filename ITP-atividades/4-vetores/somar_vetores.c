#include <stdio.h>

int main()
{
	int vetor1[5], vetor2[5], soma[5];

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &vetor1[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &vetor2[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		soma[i] = vetor1[i] + vetor2[i];
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", soma[i]);
	}

	return 0;
}
