#include <stdio.h>
#include <string.h>

int main()
{
	char numero[25], paridade[10] = "impar", ePalindromo[10] = "é";

	scanf("%s", numero);

	int tamanho = strlen(numero);

	int ultimo_digito = numero[tamanho - 1] - '0';
	if (ultimo_digito % 2 == 0)
	{
		strcpy(paridade, "par");
	}

	int e_palindromo = 1;
	for (int i = 0, j = tamanho - 1; i < j; i++, j--)
	{
		if (numero[i] != numero[j])
		{
			strcpy(ePalindromo, "não é");
			break;
		}
	}

	printf("%s %s Palíndromo e %s.", numero, ePalindromo, paridade);

	return 0;
}