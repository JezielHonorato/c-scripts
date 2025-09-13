#include <stdio.h>

int main()
{
	int t1, t2;
	
	scanf("%d", &t1);
	int vetor[t1];

	for (int i = 0; i < t1; i++)
	{
		scanf("%d", &vetor[i]);
	}

	scanf("%d", &t2);
	int vetor2[t2];
	for (int i = 0; i < t2; i++)
	{
		scanf("%d", &vetor2[i]);
	}

	int vetor3[t1 + t2];

	for (int i = 0; i < t1; i++)
	{
		vetor3[i] = vetor[i];
	}

	for (int i = 0; i < t2; i++)
	{
		vetor3[t1 + i] = vetor2[i];
	}

	for (int i = 0; i < t1 + t2; i++)
	{
		printf("%d ", vetor3[i]);
	}

	return 0;
}
