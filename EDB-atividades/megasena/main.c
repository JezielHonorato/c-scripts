#include "megasena.h"
#include <stdio.h>

int main()
{
	TabelaHash tabela;
	int opcao;

	inicializarTabela(&tabela);
	carregarDadosArquivo(&tabela, "resultados_megasena.tsv");

	do
	{
		printf("\n===== SISTEMA MEGA-SENA =====\n");
		printf("1 - Inserir concurso\n");
		printf("2 - Buscar concurso\n");
		printf("3 - Remover concurso\n");
		printf("4 - Exibir todos os concursos\n");
		printf("5 - Calcular estatisticas\n");
		printf("6 - verificar se os numeros ja sairam\n");
		printf("7 - Consultar por ano\n");
		printf("0 - Sair\n");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			int sorteio, numeros[6], data;

			printf("\nNumero do concurso: ");
			scanf("%d", &sorteio);

			printf("Data do sorteio (AAAAMMDD): ");
			scanf("%d", data);

			printf("Digite os 6 numeros sorteados:\n");
			for (int i = 0; i < 6; i++)
			{
				printf("Numero %d: ", i + 1);
				scanf("%d", &numeros[i]);
			}

			inserirJogo(&tabela, sorteio, numeros, data);
			break;
		case 2:
			int sorteio;
			printf("\nNumero do concurso a buscar: ");
			scanf("%d", &sorteio);

			buscarJogo(&tabela, sorteio);
			break;
		case 3:
			int sorteio;
			printf("\nNumero do concurso a remover: ");
			scanf("%d", &sorteio);

			removerJogo(&tabela, sorteio);
			break;
		case 4:
			exibirTabela(&tabela);
			break;
		case 5:
			calcularEstatisticas(&tabela);
			break;
		case 6:
			int numerosSorteados[6];
			printf("Digite os 6 numeros sorteados:\n");
			for (int i = 0; i < 6; i++)
			{
				printf("Numero %d: ", i + 1);
				scanf("%d", &numerosSorteados[i]);
			}
			verificarJogo(&tabela, numerosSorteados);
			break;
		case 7:
			int ano;
			printf("Digite o ano:\n");
			scanf("%d", &ano);
			exibirConcursosAno(&tabela, ano);
			break;
		case 8:
			printf("\nEncerrando o sistema...\n");
			break;
		default:
			printf("\nOpcao invalida!\n");
			return 0;
		}
	} while (opcao != 0);

	return 0;
}
