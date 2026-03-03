#ifndef PROJETO_H
#define PROJETO_H

typedef struct
{
	char ficha[15];
	int topo;
} Pilha;

extern int foraAzul;
extern int foraVermelha;

extern Pilha casa[24], barraVermelha, barraAzul;

void iniciarTabuleiro();
void exibirTabuleiro(int turno);
int vazia(Pilha *p);
void push(Pilha *p, char ficha);
char pop(Pilha *p);
char peek(Pilha *p);
int sortearNumero();
void moverFicha(char ficha, int dado);
int capturarCasa(char ficha, int destino);
void reinserirDaBarra(int destino, char ficha);
int escolherOrigem(char ficha, int dado);
int destinoValido(int destino, char ficha);

#endif