#include <stdio.h>

int main()
{
	int tempQuantidade, quantidade = 0;
	double tempValor, valor = 0;

	do
	{
		scanf("%d %lf", &tempQuantidade, &tempValor);
		if (tempQuantidade != -1)
		{
			quantidade += tempQuantidade;
			valor += tempValor * tempQuantidade;
		}
	} while (tempQuantidade != -1);

	printf("%d %.2lf", quantidade, valor);

	return 0;
}