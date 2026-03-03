#include <stdio.h>
#include <stdlib.h>

int *somaVetores(int *a, int *b, int tamanho)
{
	int *c = (int *)malloc(tamanho * sizeof(int));
	if (c == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < tamanho; i++)
	{
		c[i] = a[i] + b[i];
	}

	return c;
}

int main()
{
	int nA = 0, nB = 0;
	int *a = NULL, *b = NULL, *c = NULL;
	int valor;

	while (scanf("%d", &valor) == 1)
	{
		a = realloc(a, (nA + 1) * sizeof(int));
		a[nA] = valor;
		nA++;

		if (getchar() == '\n')
			break;
	}

	while (scanf("%d", &valor) == 1)
	{
		b = realloc(b, (nB + 1) * sizeof(int));
		b[nB] = valor;
		nB++;

		if (getchar() == '\n')
			break;
	}

	if (nA != nB)
	{
		printf("Vetores de tamanhos diferentes!\n");
		free(a);
		free(b);
		return 0;
	}

	c = somaVetores(a, b, nA);

	for (int i = 0; i < nA; i++)
	{
		printf("%d ", c[i]);
	}

	free(a);
	free(b);
	free(c);

	return 0;
}
