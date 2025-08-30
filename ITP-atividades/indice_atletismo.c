#include <stdio.h>

int main()
{
	int anos = 0;
	double distancia, media = 0;
	scanf("%d", &anos);
	for (int i = anos; i > 0; --i)
	{
		scanf("%lf", &distancia);
		if (distancia == -1)
		{
			anos -= 1;
		}
		else
		{
			media += distancia;
		}
	}
	if (media > 0)
	{
		printf("%.2lf", media / anos);
	}
	else
	{
		printf("A competicao nao possui dados historicos!");
	}

	return 0;
}