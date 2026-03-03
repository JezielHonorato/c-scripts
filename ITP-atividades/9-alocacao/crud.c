#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nome[200];
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

Pessoa *inserir(Pessoa *v, int *n, Pessoa p)
{
	v = realloc(v, (*n + 1) * sizeof(Pessoa));
	v[*n] = p;
	(*n)++;
	return v;
}

Pessoa *deletar(Pessoa *v, int *n, Pessoa p)
{
	int i, j;
	for (i = 0; i < *n; i++)
	{
		if (strcmp(v[i].nome, p.nome) == 0 && v[i].idade == p.idade && v[i].sexo == p.sexo)
		{
			for (j = i; j < *n - 1; j++)
				v[j] = v[j + 1];
			(*n)--;
			v = realloc(v, (*n) * sizeof(Pessoa));
			break;
		}
	}
	return v;
}

void imprimir(Pessoa *v, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%s,%d,%c\n", v[i].nome,  v[i].idade, v[i].sexo);
	}
}

int main()
{
	Pessoa *vet = NULL;
	int n = 0;
	char op;
	char nome[200];
	int idade;
	char sexo;

	while (scanf(" %c", &op) != EOF)
	{
		if (op == 'i')
		{
			scanf(" %199[^\n]", nome);
			scanf("%d", &idade);
			scanf(" %c", &sexo);
			Pessoa p = criar(nome, idade, sexo);
			vet = inserir(vet, &n, p);
		}
		else if (op == 'd')
		{
			scanf(" %199[^\n]", nome);
			scanf("%d", &idade);
			scanf(" %c", &sexo);
			Pessoa p = criar(nome, idade, sexo);
			vet = deletar(vet, &n, p);
		}
		else if (op == 'p')
		{
			imprimir(vet, n);
			break;
		}
	}

	free(vet);
	return 0;
}
