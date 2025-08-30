#include <stdio.h>

int main()
{
	int numero, i = 1;

	scanf("%d", &numero);
	if (numero < 1)
	{
		printf("Você entrou com %d, tente de novo na próxima", numero);
	}

	for (int j = 1; j <= numero; ++j)
	{
		for (int k = 1; k <= j; ++k)
		{
			{
				printf("%2d ", i);
			}
			++i;
		}
		printf("\n");
	}

	return 0;
}