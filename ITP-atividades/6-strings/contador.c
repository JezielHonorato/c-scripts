#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char A[41], B[41];
	int tamanhoA, tamanhoB, repeticoes = 0, posicoes[40], posCount = 0;
	int igual;

	fgets(A, sizeof(A), stdin);
	A[strcspn(A, "\n")] = '\0';
	fgets(B, sizeof(B), stdin);
	B[strcspn(B, "\n")] = '\0';

	tamanhoA = strlen(A);
	tamanhoB = strlen(B);

	for (int i = 0; i <= tamanhoB - tamanhoA; i++)
	{
		igual = 1;
		for (int j = 0; j < tamanhoA; j++)
		{
			if (tolower(B[i + j]) != tolower(A[j]))
			{
				igual = 0;
				break;
			}
		}
		if (igual)
		{
			repeticoes++;
			posicoes[posCount++] = i;
		}
	}

	printf("Repetições: %d\n", repeticoes);
	if (repeticoes != 0)
	{
		printf("Posições:");
		for (int k = 0; k < posCount; k++)
		{
			printf(" %d", posicoes[k]);
		}
	}

	return 0;
}
