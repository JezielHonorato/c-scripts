#include <stdio.h>
#include <string.h>

int main()
{
	char frutas[8][50], busca[50];
	int i, encontrado = 0;

	for (i = 0; i < 8; i++)
	{
		scanf("%s", frutas[i]);
	}

	scanf("%s", busca);

	for (i = 0; i < 8; i++)
	{
		if (strcmp(frutas[i], busca) == 0)
		{
			printf("encontrei\n");
			encontrado = 1;
		}
		else
		{
			printf("não\n");
		}
	}

	return 0;
}
