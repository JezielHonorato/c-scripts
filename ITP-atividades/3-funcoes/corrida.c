#include <stdio.h>

int nivel(int velocidade);

int main()
{
	int velocidade = 0, tempvelocidade, quantidade;

	scanf("%d", &quantidade);
	for (quantidade; quantidade > 0; --quantidade)
	{
		scanf("%d", &tempvelocidade);
		if (tempvelocidade > velocidade)
		{
			velocidade = tempvelocidade;
		}
	}

	printf("Level %d", nivel(velocidade));

	return 0;
}

int nivel(int velocidade)
{
	if (velocidade < 20)
	{
		if (velocidade < 10)
		{
			return 1;
		}
		return 2;
	}
	return 3;
}