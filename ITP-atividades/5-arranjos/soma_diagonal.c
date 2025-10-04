#include <stdio.h>

int somaDiagonais(int n, int matriz[10][10]);

int main()
{
	int n;
	int matriz[10][10];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matriz[i][j]);
		}
	}

	printf("%d\n", somaDiagonais(n, matriz));
	return 0;
}

int somaDiagonais(int n, int matriz[10][10])
{
	int soma = 0;
	for (int i = 0; i < n; i++)
	{
		soma += matriz[i][i];
		soma += matriz[i][n - i - 1];
	}
	return soma;
}