#include <stdio.h>
#include <string.h>

typedef struct
{
	char nome[50];
	int idade;
	char sexo;
} Pessoa;

Pessoa criar(char nome[], int idade, char sexo)
{
	Pessoa p;
	strcpy(p.nome, nome);
	p.idade = idade;
	p.sexo = sexo;
	return p;
}

void inserir(Pessoa vetor[], int *n, Pessoa p)
{
	vetor[*n] = p;
	(*n)++;
}

void deletar(Pessoa vetor[], int *n, Pessoa p)
{
	for (int i = 0; i < *n; i++)
	{
		if (strcmp(vetor[i].nome, p.nome) == 0 && vetor[i].idade == p.idade && vetor[i].sexo == p.sexo)
		{
			for (int j = i; j < *n - 1; j++)
			{
				vetor[j] = vetor[j + 1];
			}
			(*n)--;
			break;
		}
	}
}

void imprimir(Pessoa vetor[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s,%d,%c\n", vetor[i].nome, vetor[i].idade, vetor[i].sexo);
	}
}

int main()
{
	Pessoa pessoas[100];
	int n = 0;
	char comando;
	char nome[50];
	int idade;
	char sexo;

	while (1)
	{
		scanf(" %c", &comando);

		if (comando == 'i')
		{
			scanf(" %[^\n]", nome);
			scanf("%d", &idade);
			scanf(" %c", &sexo);
			Pessoa p = criar(nome, idade, sexo);
			inserir(pessoas, &n, p);
		}
		else if (comando == 'd')
		{
			scanf(" %[^\n]", nome);
			scanf("%d", &idade);
			scanf(" %c", &sexo);
			Pessoa p = criar(nome, idade, sexo);
			deletar(pessoas, &n, p);
		}
		else if (comando == 'p')
		{
			imprimir(pessoas, n);
			break;
		}
	}

	return 0;
}
