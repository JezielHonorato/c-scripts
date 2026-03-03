#include "megasena.h"
#include <stdio.h>
#include <stdlib.h>

int encontrarHash(int sorteio) // Calcula o índice da tabela hash a partir do número do sorteio
{
	return sorteio % N;
}

void inicializarTabela(TabelaHash *tabela) // Cria uma tabela com o tamanho definido e espaços vazios
{
	for (int i = 0; i < N; i++)
		tabela->tabela[i] = NULL;
}

void inserirJogo(TabelaHash *tabela, int sorteio, int numerosSorteados[6], int data)
{
	int indice = encontrarHash(sorteio); // encontra o índice do sorteio
	Jogo *atual = tabela->tabela[indice];

	while (atual != NULL) // Verifica se já existe um concurso com o mesmo número
	{
		if (atual->sorteio == sorteio)
		{
			printf("Erro: concurso %d ja cadastrado.\n", sorteio); // Se positivo informa que o concurso já foi sorteado
			return;
		}
		atual = atual->next;
	}

	Jogo *novo_jogo = (Jogo *)malloc(sizeof(Jogo)); // Verifica se já existe um concurso com o mesmo número

	if (novo_jogo == NULL) // Verifica se a alocação de memória foi feita corretamente
	{
		printf("Erro: falha na alocação de memoria.\n");
		return;
	}

	novo_jogo->sorteio = sorteio; // Armazena o número do sorteio

	// Copia os números sorteados
	for (int i = 0; i < 6; i++)
	{
		novo_jogo->numerosSorteados[i] = numerosSorteados[i];
	}

	// Copia os dados de data

	novo_jogo->data = data;

	// Inserção no início da lista encadeada
	novo_jogo->next = tabela->tabela[indice];
	tabela->tabela[indice] = novo_jogo;
}

void buscarJogo(TabelaHash *tabela, int sorteio)
{
	int indice = encontrarHash(sorteio);
	Jogo *atual = tabela->tabela[indice];

	while (atual != NULL)
	{
		if (atual->sorteio == sorteio)
		{
			printf("Concurso %d encontrado\n", sorteio);
			printf("Data do sorteio:");
			imprimirData(atual->data);
			printf("\nNumeros sorteados: ");

			for (int i = 0; i < 6; i++)
				printf("%d ", atual->numerosSorteados[i]);

			printf("\n");
			return;
		}
		atual = atual->next;
	}

	printf("Erro: concurso %d nao encontrado.\n", sorteio); // Retorna a mensagem caso o concurso buscado não exista
}

void removerJogo(TabelaHash *tabela, int sorteio)
{
	int indice = encontrarHash(sorteio);
	Jogo *atual = tabela->tabela[indice];
	Jogo *anterior = NULL;

	while (atual != NULL)
	{
		if (atual->sorteio == sorteio)
		{
			if (anterior == NULL)
			{
				tabela->tabela[indice] = atual->next;
			}
			else
			{
				anterior->next = atual->next;
			}
			free(atual);
			return;
		}
		anterior = atual;
		atual = atual->next;
	}
	printf("Sorteio %d nao encontrada para remocao.\n", sorteio);
}

void exibirTabela(TabelaHash *tabela)
{
	int vazia = 1;

	for (int i = 0; i < N; i++)
	{
		Jogo *atual = tabela->tabela[i];

		if (atual != NULL)
		{
			vazia = 0;
			printf("Indice %d:\n", i);

			while (atual != NULL)
			{
				printf("  Concurso: %d\n", atual->sorteio);
				printf("  Data:");
				imprimirData(atual->data);

				printf("\n  Numeros sorteados: ");

				for (int j = 0; j < 6; j++)
					printf("%d ", atual->numerosSorteados[j]);

				printf("\n\n");
				atual = atual->next;
			}
		}
	}

	if (vazia)
	{
		printf("Tabela hash vazia. Nenhum concurso cadastrado.\n");
	}
}

void calcularEstatisticas(TabelaHash *tabela)
{
	int numeroAparicoes[59] = {0}, i, j;
	FilaPrioridade fila[59]; 

	for (i = 0; i < N; i++)
	{
		Jogo *atual = tabela->tabela[i];
		while (atual != NULL)
		{
			for (j = 0; j < 6; j++)
				numeroAparicoes[atual->numerosSorteados[j] - 1]++;
			atual = atual->next;
		}
	}

	for (i = 0; i < 60; i++)
	{
		fila[i].numero = i + 1;
		fila[i].aparicoes = numeroAparicoes[i];
	}

	bubbleSort(fila, 60);

	printf("\nOs 10 numeros mais sorteados\n");
	for (i = 0; i < 10; i++)
		printf("%2d - Numero %2d apareceu %d vezes\n", i + 1, fila[i].numero, fila[i].aparicoes);

	printf("\nOs 10 numeros menos sorteados\n");
	for (i = 59; i > 49; i--)
		printf("%2d - Numero %2d apareceu %d vezes\n", 60 - i, fila[i].numero, fila[i].aparicoes);
}

void verificarJogo(TabelaHash *tabela, int numerosSorteados[6])
{
	int boolean = 0;
	for (int i = 0; i < N; i++)
	{
		Jogo *atual = tabela->tabela[i];
		while (atual != NULL)
		{
			if (verificarNumerosSorteados(numerosSorteados, atual->numerosSorteados) == 1)
			{
				boolean = 1;
				printf("Concurso %d encontrado\n", atual->sorteio);
				printf("Data do sorteio:");
				imprimirData(atual->data);
				printf("\nNumeros sorteados: ");

				for (int i = 0; i < 6; i++)
					printf("%d ", atual->numerosSorteados[i]);

				printf("\n");
			}
			atual = atual->next;
		}
	}
	if (boolean == 0)
		printf("Ate o momento nao existe nenhum jogo com estes numeros");
}

int verificarNumerosSorteados(int vetor1[6], int vetor2[6])
{
	int v1[6], v2[6], i;
	for (i = 0; i < 6; i++)
	{
		v1[i] = vetor1[i];
		v2[i] = vetor2[i];
	}

	bubbleSortInt(v1, 6);
	bubbleSortInt(v2, 6);

	for (int i = 0; i < 6; i++)
		if (v1[i] != v2[i])
			return 0;

	return 1;
}

void exibirConcursosAno(TabelaHash *tabela, int ano)
{
	if (ano < 1996 || ano > 2026)
	{
		printf("Ano %d fora do intervalo de operacao\n", ano);
		return;
	}

	int contador = 0;
	printf("\nSorteios de %d\n", ano);

	for (int i = 0; i < N; i++)
	{
		Jogo *atual = tabela->tabela[i];
		while (atual != NULL)
		{
			int anoJogo = atual->data / 10000;

			if (anoJogo == ano)
			{
				printf("Concurso %d encontrado\n", atual->sorteio);
				printf("Data do sorteio:");
				imprimirData(atual->data);
				printf("\nNumeros sorteados: ");
				for (int i = 0; i < 6; i++)
					printf("%d ", atual->numerosSorteados[i]);

				printf("\n\n");
				contador++;
			}
			atual = atual->next;
		}
	}

	if (contador == 0)
		printf("Nenhum concurso encontrado para o ano %d.\n", ano);
	else
		printf("Total de concursos em %d: %d\n", ano, contador);
}

void bubbleSort(FilaPrioridade vetor[], int n)
{
	for (int i = 0; i < (n - 1); i++)
		for (int j = 0; j < (n - i - 1); j++)
			if (vetor[j].aparicoes < vetor[j + 1].aparicoes)
			{
				FilaPrioridade temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
}

void bubbleSortInt(int vetor[], int n)
{
	for (int i = 0; i < (n - 1); i++)
		for (int j = 0; j < (n - i - 1); j++)
			if (vetor[j] < vetor[j + 1])
			{
				int temp = vetor[j];
				vetor[j] = vetor[j + 1];
				vetor[j + 1] = temp;
			}
}

void imprimirData(int data)
{
	int ano = data / 10000;
	int mes = (data / 100) % 100;
	int dia = data % 100;

	printf("%02d/%02d/%04d", dia, mes, ano);
}

void carregarDadosArquivo(TabelaHash *tabela, const char *nomeArquivo)
{
	FILE *file = fopen(nomeArquivo, "r");
	if (file == NULL)
	{
		printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
		return;
	}

	int sorteio, b[6], dia, mes, ano;
	char dataStr[11];
	char buffer[256];

	fgets(buffer, sizeof(buffer), file);

	while (fscanf(file, "%d %s %d %d %d %d %d %d", &sorteio, dataStr, &b[0], &b[1], &b[2], &b[3], &b[4], &b[5]) == 8)
	{
		printf("Lendo concurso: %d\n", sorteio);

		sscanf(dataStr, "%d/%d/%d", &dia, &mes, &ano);
		int dataInt = (ano * 10000) + (mes * 100) + dia;

		inserirJogo(tabela, sorteio, b, dataInt);
	}

	fclose(file);
	printf("Dados carregados com sucesso\n");
}