#include <stdio.h>

void subtrairMatrizes(int m, int n, int A[m][n], int B[m][n], int R[m][n]);

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	int A[m][n], B[m][n], R[m][n];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &B[i][j]);
		}
	}

	subtrairMatrizes(m, n, A, B, R);

	printf("Resultado:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}

	int cont = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > j && R[i][j] != 0)
			{
				cont++;
			}
		}
	}

	printf("Elementos não-nulos na região: %d\n", cont);

	return 0;
}

void subtrairMatrizes(int m, int n, int A[m][n], int B[m][n], int R[m][n])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			R[i][j] = A[i][j] - B[i][j];
		}
	}
}
