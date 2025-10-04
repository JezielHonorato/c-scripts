#include <stdio.h>

int ehSimetrica(int n, int matriz[10][10])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (matriz[i][j] != matriz[j][i])
			{
				return 0;
			}
		}
	}
	return 1;
}

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

	if (ehSimetrica(n, matriz))
	{
		printf("A matriz e simetrica\n");
	}
	else
	{
		printf("A matriz nao e simetrica\n");
	}

	return 0;
}
