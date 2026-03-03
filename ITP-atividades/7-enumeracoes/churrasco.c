#include <stdio.h>
#include <string.h>

struct Item
{
	char nome[50];
	float preco;
	int quantidade;
};

int main()
{
	struct Item itens[500];
	int opcao, qtdItens = 0, i;
	int pessoas;
	float total = 0;

	do
	{
		scanf(" %[^\n]", itens[qtdItens].nome);
		scanf("%f", &itens[qtdItens].preco);
		scanf("%d", &itens[qtdItens].quantidade);

		qtdItens++;

		scanf("%d", &opcao);

	} while (opcao == 1);

	scanf("%d", &pessoas);

	for (i = 0; i < qtdItens; i++)
	{
		total += itens[i].preco * itens[i].quantidade;
	}

	printf("Valor: R$ %.2f\n", total);
	printf("Divisão R$ %.2f para cada participante.", total / pessoas);

	return 0;
}
