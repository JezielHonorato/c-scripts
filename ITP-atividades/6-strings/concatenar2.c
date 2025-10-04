#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	char linha[100], resultado[100] = "", temp[100];

	while (1)
	{
		scanf("%d", &n);
		getchar();

		if (n == -1)
			break;

		fgets(linha, sizeof(linha), stdin);
		linha[strcspn(linha, "\n")] = '\0';

		if (n == 1)
		{
			strcat(resultado, linha);
		}
		else if (n == 0)
		{
			strcpy(temp, linha);
			strcat(temp, resultado);
			strcpy(resultado, temp);
		}
	}

	printf("%s\n", resultado);
	return 0;
}
