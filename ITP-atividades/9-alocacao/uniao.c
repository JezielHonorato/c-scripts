#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *v;
	int n;
} Conjunto;

int existe(int *v, int n, int x)
{
	for (int i = 0; i < n; i++)
		if (v[i] == x)
			return 1;
	return 0;
}

Conjunto uniao(Conjunto A, Conjunto B)
{
	Conjunto U;
	U.v = NULL;
	U.n = 0;

	for (int i = 0; i < A.n; i++)
	{
		if (!existe(U.v, U.n, A.v[i]))
		{
			U.v = realloc(U.v, (U.n + 1) * sizeof(int));
			U.v[U.n++] = A.v[i];
		}
	}

	for (int i = 0; i < B.n; i++)
	{
		if (!existe(U.v, U.n, B.v[i]))
		{
			U.v = realloc(U.v, (U.n + 1) * sizeof(int));
			U.v[U.n++] = B.v[i];
		}
	}

	return U;
}

Conjunto intersecao(Conjunto A, Conjunto B)
{
	Conjunto I;
	I.v = NULL;
	I.n = 0;

	for (int i = 0; i < B.n; i++)
	{
		if (existe(A.v, A.n, B.v[i]))
		{
			I.v = realloc(I.v, (I.n + 1) * sizeof(int));
			I.v[I.n++] = B.v[i];
		}
	}

	return I;
}

void imprime(char *titulo, Conjunto C)
{
	printf("%s == ", titulo);
	if (C.n == 0)
	{
		printf("{vazio}\n");
		return;
	}
	printf("{");
	for (int i = 0; i < C.n; i++)
	{
		printf("%d", C.v[i]);
		if (i < C.n - 1)
			printf(" ");
	}
	printf("}\n");
}

int main()
{
	Conjunto A, B, U, I;
	int tam;

	scanf("%d", &tam);
	A.n = tam;
	A.v = malloc(tam * sizeof(int));
	for (int i = 0; i < tam; i++)
		scanf("%d", &A.v[i]);

	scanf("%d", &tam);
	B.n = tam;
	B.v = malloc(tam * sizeof(int));
	for (int i = 0; i < tam; i++)
		scanf("%d", &B.v[i]);

	U = uniao(A, B);
	I = intersecao(A, B);

	imprime("A união B", U);
	imprime("A interseção B", I);

	free(A.v);
	free(B.v);
	free(U.v);
	free(I.v);

	return 0;
}
