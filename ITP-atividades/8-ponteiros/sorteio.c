#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
	char **participantes = NULL;
	char nome[100];
	int N = 0;

	while (1)
	{
		fgets(nome, sizeof(nome), stdin);
		nome[strcspn(nome, "\n")] = 0;
		if (strcmp(nome, "acabou") == 0)
			break;
		participantes = realloc(participantes, (N + 1) * sizeof(char *));
		participantes[N] = malloc(strlen(nome) + 1);
		strcpy(participantes[N], nome);
		N++;
	}

	int semente;
	scanf("%d", &semente);
	srand(semente);

	int *sorteado = calloc(N, sizeof(int));
	int cont = 0;

	while (cont < N)
	{
		int indice = rand() % N;
		if (!sorteado[indice])
		{
			printf("%s\n", participantes[indice]);
			sorteado[indice] = 1;
			cont++;
		}
	}

	for (int i = 0; i < N; i++)
		free(participantes[i]);
	free(participantes);
	free(sorteado);
	return 0;
}
