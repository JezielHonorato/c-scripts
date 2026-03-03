#ifndef MEGASENA_H
#define MEGASENA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct jogo
{
	int sorteio;
	int numerosSorteados[6];
	int data; // 29.01.2026 = 20260129
	struct jogo *next;
} Jogo;

typedef struct FilaPrioridade
{
	int numero;
	int aparicoes;
} FilaPrioridade;

typedef struct
{
	Jogo *tabela[N];
} TabelaHash;

int encontrarHash(int sorteio);
void inicializarTabela(TabelaHash *tabela);
void inserirJogo(TabelaHash *tabela, int sorteio, int numerosSorteados[6], int data);
void removerJogo(TabelaHash *tabela, int sorteio);
void buscarJogo(TabelaHash *tabela, int sorteio);
void exibirTabela(TabelaHash *tabela);
void imprimirData(int data);

void carregarDadosArquivo(TabelaHash *tabela, const char *nomeArquivo);
void calcularEstatisticas(TabelaHash *tabela);
void verificarJogo(TabelaHash *tabela, int numerosSorteados[6]);
void exibirConcursosAno(TabelaHash *tabela, int ano);
int verificarNumerosSorteados(int vetor1[6], int vetor2[6]);
void bubbleSort(FilaPrioridade vetor[], int n);
void bubbleSortInt(int vetor[], int n);

#endif
