#include <stdio.h>

int main()
{
	int A[20], pares[20], impares[20], pares_count = 0, impares_count = 0;

	for (int i = 0; i < 20; i++)
	{
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		if (A[i] % 2 == 0)
		{
			pares[pares_count] = A[i];
			pares_count++;
		}
		else
		{
			impares[impares_count] = A[i];
			impares_count++;
		}
	}

	printf("Pares: ");
	for (int i = 0; i < pares_count; i++)
	{
		if (i > 0)
		{
			printf(",");
		}
		printf("%d", pares[i]);
	}
	printf("\n");

	printf("Impares: ");
	for (int i = 0; i < impares_count; i++)
	{
		if (i > 0)
		{
			printf(",");
		}
		printf("%d", impares[i]);
	}
	printf("\n");

	return 0;
}