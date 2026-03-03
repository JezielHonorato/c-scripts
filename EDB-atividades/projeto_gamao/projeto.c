#include <stdio.h>
#include <stdlib.h>
#include "projeto.h"

// variaveis globais
int foraAzul = 0;
int foraVermelha = 0;
Pilha casa[24], barraVermelha, barraAzul;

void iniciarTabuleiro() // coloca as pecas iniciais do tabuleiro
{
	for (int i = 0; i < 24; i++)
		casa[i].topo = -1;

	barraVermelha.topo = -1;
	barraAzul.topo = -1;
	foraAzul = 0;
	foraVermelha = 0;

	push(&casa[0], 'a');
	push(&casa[0], 'a');
	for (int i = 0; i < 5; i++)
		push(&casa[5], 'v');
	for (int i = 0; i < 3; i++)
		push(&casa[7], 'v');
	for (int i = 0; i < 5; i++)
		push(&casa[11], 'a');
	for (int i = 0; i < 5; i++)
		push(&casa[12], 'v');
	for (int i = 0; i < 3; i++)
		push(&casa[16], 'a');
	for (int i = 0; i < 5; i++)
		push(&casa[18], 'a');
	push(&casa[23], 'v');
	push(&casa[23], 'v');
}

void exibirTabuleiro(int turno)
{
	printf("\n================ TABULEIRO - TURNO %d ================\n", turno);
	for (int i = 12; i < 24; i++)
	{
		if (vazia(&casa[i]))
			printf("[%02d]--  ", i + 1);
		else
			printf("[%02d]%c%d  ", i + 1, peek(&casa[i]), casa[i].topo + 1);
	}
	printf("\n --------------------------------------------------------------------------\n");
	for (int i = 11; i >= 0; i--)
	{
		if (vazia(&casa[i]))
			printf("[%02d]--  ", i + 1);
		else
			printf("[%02d]%c%d  ", i + 1, peek(&casa[i]), casa[i].topo + 1);
	}
	printf("\n\n [BARRA] Azul: %d | Vermelha: %d  [FORA] Azul: %d | Vermelha: %d\n",
		   barraAzul.topo + 1, barraVermelha.topo + 1, foraAzul, foraVermelha);
}

int vazia(Pilha *p)
{
	return p->topo == -1;
}

void push(Pilha *p, char ficha)
{
	if (p->topo < 14)
		p->ficha[++p->topo] = ficha;
}

char pop(Pilha *p)
{
	if (!vazia(p))
		return p->ficha[p->topo--];
	return '-';
}

char peek(Pilha *p)
{
	if (!vazia(p))
		return p->ficha[p->topo];
	return '-';
}

int sortearNumero()
{
	return (rand() % 6) + 1; // sorteia um numero entre 0 e 5 e soma 1
}

void moverFicha(char ficha, int dado)
{
	int origem, destino;
	if (ficha == 'v' && !vazia(&barraVermelha))
	{
		reinserirDaBarra(24 - dado, ficha); // as vermelhas voltam e as azuis vao
		return;
	}
	if (ficha == 'a' && !vazia(&barraAzul))
	{
		reinserirDaBarra(dado - 1, ficha);
		return;
	}

	origem = escolherOrigem(ficha, dado);
	if (origem == -1)
		return;

	if (ficha == 'a')
		destino = origem + dado;
	else
		origem - dado;

	if (destino > 23 && ficha == 'a')
	{
		pop(&casa[origem]);
		foraAzul++;
	}
	else if (destino < 0 && ficha == 'v')
	{
		pop(&casa[origem]);
		foraVermelha++;
	}
	else
	{
		if (capturarCasa(ficha, destino))
			pop(&casa[origem]);
	}
}

int capturarCasa(char ficha, int destino)
{
	if (destino < 0 || destino > 23)
		return 0;
	if (vazia(&casa[destino]) || peek(&casa[destino]) == ficha) // se estiver vazia ou a de cima for a mesma
	{
		push(&casa[destino], ficha);
		return 1;
	}
	else if (casa[destino].topo == 0) // se tiver so uma da outra cor
	{
		char capturada = pop(&casa[destino]);
		push(&casa[destino], ficha);
		if (capturada == 'a')
			push(&barraAzul, 'a');
		else
			push(&barraVermelha, 'v');
		return 1;
	}
	return 0; // else {faz nada}
}

void reinserirDaBarra(int destino, char ficha)
{
	if (capturarCasa(ficha, destino))
	{
		if (ficha == 'v')
			pop(&barraVermelha);
		else
			pop(&barraAzul);
	}
}

int escolherOrigem(char ficha, int dado)
{
	if (ficha == 'a')
	{
		for (int i = 0; i < 24; i++) // pega a azul de menor indice
			if (!vazia(&casa[i]) && peek(&casa[i]) == 'a')
				if (destinoValido(i + dado, 'a') || i + dado > 23)
					return i;
	}
	else
	{
		for (int i = 23; i >= 0; i--) // pega a vermelha de maior indice
			if (!vazia(&casa[i]) && peek(&casa[i]) == 'v')
				if (destinoValido(i - dado, 'v') || i - dado < 0)
					return i;
	}
	return -1;
}

int destinoValido(int destino, char ficha)
{
	if (destino < 0 || destino > 23)
		return 0;
	return (vazia(&casa[destino]) || peek(&casa[destino]) == ficha || casa[destino].topo == 0);
}