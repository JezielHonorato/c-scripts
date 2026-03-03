#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"

ListaContatos *criarLista()
{
	ListaContatos *lista = malloc(sizeof(ListaContatos));
	lista->dados = NULL;
	lista->tamanho = 0;
	return lista;
}

void destruirLista(ListaContatos *lista)
{
	free(lista->dados);
	free(lista);
	printf("Lista destruida\n");
}

void adicionarContato(ListaContatos *lista, char nome[], char numero[])
{
	lista->dados = realloc(lista->dados, (lista->tamanho + 1) * sizeof(Contato));

	strcpy(lista->dados[lista->tamanho].nome, nome);
	strcpy(lista->dados[lista->tamanho].numero, numero);

	lista->tamanho++;
}

int buscarContato(ListaContatos *lista, char nome[])
{
	for (int i = 0; i < lista->tamanho; i++)
	{
		if (strcmp(lista->dados[i].nome, nome) == 0)
			return i;
	}
	return -1;
}

void contatoExiste(ListaContatos *lista, char nome[])
{
	int bool = buscarContato(lista, nome);
	if (bool == -1)
		printf("O contato nao existe\n");
	else
		printf("O contato %s existe\n", nome);
}

void removerContato(ListaContatos *lista, char nome[])
{
	int i = buscarContato(lista, nome);
	if (i == -1)
		printf("O contato nao existe\n");
	for (int j = i; j < lista->tamanho - 1; j++)
		lista->dados[j] = lista->dados[j + 1];

	lista->tamanho--;
	lista->dados = realloc(lista->dados, lista->tamanho * sizeof(Contato));
	printf("O contato de %s foi removido\n", nome);
}

void atualizarContato(ListaContatos *lista, char nome[], char novoNumero[])
{
	int i = buscarContato(lista, nome);
	if (i > -1)
		printf("O contato nao existe\n");
	else
	{
		strcpy(lista->dados[i].numero, novoNumero);
		printf("Contato atualizado\n");
	}
}

void listarContatos(ListaContatos *lista)
{
	for (int i = 0; i < lista->tamanho; i++)
	{
		printf("Nome: %s | Numero: %s\n", lista->dados[i].nome, lista->dados[i].numero);
	}
}

void totalContatos(ListaContatos *lista)
{
	printf("Voce tem %d contato(s)\n", lista->tamanho);
}
