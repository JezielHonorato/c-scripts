#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[50], limpa[50];
	int i, j = 0, tamanho, palindromo = 1;

	fgets(str, sizeof(str), stdin);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\n')
		{
			limpa[j++] = str[i];
		}
	}
	limpa[j] = '\0';

	tamanho = strlen(limpa);

	for (i = 0; i < tamanho / 2; i++)
	{
		if (tolower(limpa[i]) != tolower(limpa[tamanho - i - 1]))
		{
			palindromo = 0;
			break;
		}
	}

	if (palindromo)
		printf("É palíndromo\n");
	else
		printf("Não é palíndromo\n");

	return 0;
}
