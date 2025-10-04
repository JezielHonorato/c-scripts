#include <stdio.h>

void somarMatrizes(int m, int n, int A[m][n], int B[m][n], int R[m][n]);

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

	somarMatrizes(m, n, A, B, R);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void somarMatrizes(int m, int n, int A[m][n], int B[m][n], int R[m][n])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			R[i][j] = A[i][j] + B[i][j];
		}
	}
}
