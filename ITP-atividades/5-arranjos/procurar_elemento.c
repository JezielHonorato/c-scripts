#include <stdio.h>

int main()
{
	int n, m, x;
	int matriz[30][30];
	int encontrado = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &matriz[i][j]);
		}
	}

	scanf("%d", &x);

	for (int i = 0; i < n && !encontrado; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matriz[i][j] == x)
			{
				encontrado = 1;
				break;
			}
		}
	}

	if (encontrado)
		printf("Matriz tem elemento %d\n", x);
	else
		printf("Matriz não tem elemento %d\n", x);

	return 0;
}
