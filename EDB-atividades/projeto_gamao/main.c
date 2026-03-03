#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "projeto.h"

int main()
{
	srand(time(NULL));
	int turno = 1;
	iniciarTabuleiro();

	while (foraAzul < 15 && foraVermelha < 15 && turno < 100)
	{
		int d1 = sortearNumero();
		int d2 = sortearNumero();
		char ficha;
		if (turno % 2 == 0)
			ficha = 'v';
		else
			ficha = 'a';

		printf("\nJOGADOR %c - DADOS: %d, %d | PLACAR: A%d V%d\n", ficha, d1, d2, foraAzul, foraVermelha);

		int jogadas = 2, valorDoDado;
		if (d1 == d2)
			jogadas = 4;

		for (int i = 0; i < jogadas; i++)
		{
			if (d1 == d2)
				valorDoDado = d1;
			else
			{
				if (i == 0)
					valorDoDado = d1;
				else
					valorDoDado = d2;
			}

			moverFicha(ficha, valorDoDado);

			if (foraAzul == 15 || foraVermelha == 15)
				break;
		}

		exibirTabuleiro(turno);
		turno++;
	}

	if (foraAzul >= 15)
		printf("\n*** VITORIA DO AZUL! ***\n");
	else if (foraVermelha >= 15)
		printf("\n*** VITORIA DO VERMELHO! ***\n");
	else
		printf("\nEMPATE POR LIMITE DE TURNOS.\n");

	return 0;
}