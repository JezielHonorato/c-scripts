#include <stdio.h>

int main()
{
	int l, c;
	scanf("%d", &l);
	scanf("%d", &c);

	int A[l][c], B[c][l];

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < c; j++)
		{
			B[j][i] = A[i][j];
		}
	}

	printf("Transposta\n");
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < l; j++)
		{
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}

	return 0;
}
