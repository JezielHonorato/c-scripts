#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char **p;
	char nome[200];
	int n = 0, i;
	p = NULL;

	while (1)
	{
		fgets(nome, 200, stdin);
		nome[strcspn(nome, "\n")] = 0;
		if (strcmp(nome, "acabou") == 0)
			break;
		p = realloc(p, (n + 1) * sizeof(char *));
		p[n] = malloc(strlen(nome) + 1);
		strcpy(p[n], nome);
		n++;
	}

	int s;
	scanf("%d", &s);
	srand(s);

	int *usado = calloc(n, sizeof(int));
	int sorteados = 0;

	while (sorteados < n)
	{
		int ind = rand() % n;
		if (!usado[ind])
		{
			usado[ind] = 1;
			printf("%s\n", p[ind]);
			sorteados++;
		}
	}

	for (i = 0; i < n; i++)
		free(p[i]);
	free(p);
	free(usado);

	return 0;
}
