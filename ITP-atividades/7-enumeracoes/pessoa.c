#include <stdio.h>

struct tPessoa
{
	char nome[100];
	int telefone;
};

int main()
{
	struct tPessoa pessoas[100];
	int N, i;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf(" %[^\n]", pessoas[i].nome);
		scanf("%d", &pessoas[i].telefone);
	}

	for (i = 0; i < N; i++)
	{
		printf("O telefone de %s é %d\n", pessoas[i].nome, pessoas[i].telefone);
	}

	return 0;
}
