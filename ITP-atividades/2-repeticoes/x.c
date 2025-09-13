#include <stdio.h>

int main()
{
	int numero;
	char letra;

	scanf("%d %c", &numero, &letra);

	for (int i = 1; i < numero; i++)
	{
		for (int j = 1; j < numero; j++)
		{
			if (i == j || i + j == numero)
			{
				printf("%c", letra);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}