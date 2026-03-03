#include <stdio.h>
#include <string.h>

struct tPessoa
{
	char nome[50];
	int telefone;
};

int main()
{
	int n, i, encontrado = 0;
	char busca[50];
	struct tPessoa pessoas[100];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf(" %[^\n]", pessoas[i].nome);
		scanf("%d", &pessoas[i].telefone);
	}

	scanf(" %[^\n]", busca);

	for (i = 0; i < n; i++)
	{
		if (strcmp(pessoas[i].nome, busca) == 0)
		{
			printf("O telefone de %s é %d\n", pessoas[i].nome, pessoas[i].telefone);
			encontrado = 1;
			break;
		}
	}

	if (!encontrado)
		printf("Nome %s não encontrado.\n", busca);

	return 0;
}
