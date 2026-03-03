#include <stdio.h>
#include "contato.h"

int main()
{
	printf("=== CRIANDO LISTA ===\n");
	ListaContatos *lista = criarLista();

	printf("\n=== ADICIONANDO CONTATOS ===\n");
	adicionarContato(lista, "Ana", "84912345678");
	adicionarContato(lista, "Joao", "84999999999");
	adicionarContato(lista, "Maria", "84988888888");
	listarContatos(lista);

	printf("\n=== BUSCAR CONTATO ===\n");
	int pos = buscarContato(lista, "Joao");
	if (pos != -1)
		printf("Contato Joao encontrado na posicao %d\n", pos);
	else
		printf("Contato Joao nao encontrado\n");

	contatoExiste(lista, "Ana");
	contatoExiste(lista, "Carlos");

	printf("\n=== ATUALIZAR CONTATO ===\n");
	atualizarContato(lista, "Maria", "84977777777");
	listarContatos(lista);

	printf("\n=== REMOVER CONTATO ===\n");
	removerContato(lista, "Joao");

	listarContatos(lista);

	printf("\n=== TOTAL DE CONTATOS ===\n");
	totalContatos(lista);

	printf("\n=== DESTRUIR LISTA ===\n");
	destruirLista(lista);

	return 0;
}
